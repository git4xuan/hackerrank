/*这部分是严蔚敏的数据结构上的函数，放在这里备用*/
//这里的有些是不能使用的，需要将伪代码转换，调试之后才可用

void InsertSort(SqList &L) {  // 算法10.1
  // 对顺序表L作直接插入排序。
  int i,j;
  for (i=2; i<=L.length; ++i)
    if (LT(L.r[i].key, L.r[i-1].key)) {
      // "<"时，需将L.r[i]插入有序子表
      L.r[0] = L.r[i];                 // 复制为哨兵
      for (j=i-1;  LT(L.r[0].key, L.r[j].key);  --j)
        L.r[j+1] = L.r[j];             // 记录后移
      L.r[j+1] = L.r[0];               // 插入到正确位置
    }
} // InsertSort


void BInsertSort(SqList &L) {  // 算法10.2
  // 对顺序表L作折半插入排序。
  int i,j,high,low,m;
  for (i=2; i<=L.length; ++i) {
    L.r[0] = L.r[i];       // 将L.r[i]暂存到L.r[0]
    low = 1;   high = i-1;
    while (low<=high) {    // 在r[low..high]中折半查找有序插入的位置
      m = (low+high)/2;                            // 折半
      if (LT(L.r[0].key, L.r[m].key)) high = m-1;  // 插入点在低半区
      else  low = m+1;                             // 插入点在高半区
    }
    for (j=i-1; j>=high+1; --j) L.r[j+1] = L.r[j];  // 记录后移
    L.r[high+1] = L.r[0];                           // 插入
  }
} // BInsertSort


void Arrange(SLinkList &SL) {  // 算法10.3
  // 根据静态链表SL中各结点的指针值调整记录位置，
  // 使得SL中记录按关键字非递减有序顺序排列
  SLNode temp;
  int i;
  int p,q;
  p = SL.r[0].next;  // p指示第一个记录的当前位置
  for (i=1; i<SL.length; ++i) {
    // SL.r[1..i-1]中记录已按关键字有序排列，
    // 第i个记录在SL中的当前位置应不小于i
    while (p<i)  // 找到第i个记录，并用p指示其在SL中当前位置
      p = SL.r[p].next;
    q = SL.r[p].next; // q指示尚未调整的表尾
    if (p!= i) {
      temp=SL.r[p];
      SL.r[p]=SL.r[i];
      SL.r[i]=temp;
      SL.r[i].next=p; // 指向被移走的记录，使得以后可由while循环找回
    }
    p=q;              // p指示尚未调整的表尾，为找第i+1个记录作准备
  }
} // Arrange

//---------------------------------
void ShellInsert(SqList &L, int dk) {  // 算法10.4
  // 对顺序表L作一趟希尔插入排序。本算法对算法10.1作了以下修改：
  //     1. 前后记录位置的增量是dk，而不是1；
  //     2. r[0]只是暂存单元，不是哨兵。当j<=0时，插入位置已找到。
  int i,j;
  for (i=dk+1; i<=L.length; ++i)
    if (LT(L.r[i].key, L.r[i-dk].key)) { // 需将L.r[i]插入有序增量子表
      L.r[0] = L.r[i];                   // 暂存在L.r[0]
      for (j=i-dk; j>0 && LT(L.r[0].key, L.r[j].key); j-=dk)
        L.r[j+dk] = L.r[j];              // 记录后移，查找插入位置
      L.r[j+dk] = L.r[0];                // 插入
    }
} // ShellInsert


void ShellSort(SqList &L, int dlta[], int t) {  // 算法10.5
   // 按增量序列dlta[0..t-1]对顺序表L作希尔排序。
   for (int k=0; k<t; ++k)
      ShellInsert(L, dlta[k]);  // 一趟增量为dlta[k]的插入排序
} // ShellSort

//--------------------------------------
int Partition(SqList &L, int low, int high) {  // 算法10.6(a)
   // 交换顺序表L中子序列L.r[low..high]的记录，使枢轴记录到位，
   // 并返回其所在位置，此时，在它之前（后）的记录均不大（小）于它
   KeyType pivotkey;
   RedType temp;
   pivotkey = L.r[low].key;     // 用子表的第一个记录作枢轴记录
   while (low<high) {           // 从表的两端交替地向中间扫描
      while (low<high && L.r[high].key>=pivotkey) --high;
      temp=L.r[low];
      L.r[low]=L.r[high];
      L.r[high]=temp;           // 将比枢轴记录小的记录交换到低端
      while (low<high && L.r[low].key<=pivotkey) ++low;
      temp=L.r[low];
      L.r[low]=L.r[high];
      L.r[high]=temp;           // 将比枢轴记录大的记录交换到高端
   }
   return low;                  // 返回枢轴所在位置
} // Partition

int Partition(SqList &L, int low, int high) {  // 算法10.6(b)
   // 交换顺序表L中子序列L.r[low..high]的记录，使枢轴记录到位，
   // 并返回其所在位置，此时，在它之前（后）的记录均不大（小）于它
   KeyType pivotkey;
   L.r[0] = L.r[low];            // 用子表的第一个记录作枢轴记录
   pivotkey = L.r[low].key;      // 枢轴记录关键字
   while (low<high) {            // 从表的两端交替地向中间扫描
      while (low<high && L.r[high].key>=pivotkey) --high;
      L.r[low] = L.r[high];      // 将比枢轴记录小的记录移到低端
      while (low<high && L.r[low].key<=pivotkey) ++low;
      L.r[high] = L.r[low];      // 将比枢轴记录大的记录移到高端
   }
   L.r[low] = L.r[0];            // 枢轴记录到位
   return low;                   // 返回枢轴位置
} // Partition

void QSort(SqList &L, int low, int high) {  //算法10.7
  // 对顺序表L中的子序列L.r[low..high]进行快速排序
  int pivotloc;
  if (low < high) {                      // 长度大于1
    pivotloc = Partition(L, low, high);  // 将L.r[low..high]一分为二
    QSort(L, low, pivotloc-1); // 对低子表递归排序，pivotloc是枢轴位置
    QSort(L, pivotloc+1, high);          // 对高子表递归排序
  }
} // QSort

void QuickSort(SqList &L) {  // 算法10.8
   // 对顺序表L进行快速排序
   QSort(L, 1, L.length);
} // QuickSort


//---------------------------------------------
void SelectSort(SqList &L) {  // 算法10.9
  // 对顺序表L作简单选择排序。
  int i,j;
  for (i=1; i<L.length; ++i) { // 选择第i小的记录，并交换到位
    j = SelectMinKey(L, i);  // 在L.r[i..L.length]中选择key最小的记录
    if (i!=j) {                // L.r[i]←→L.r[j];   与第i个记录交换
      RedType temp;
      temp=L.r[i];
      L.r[i]=L.r[j];
      L.r[j]=temp;
    }
  }
} // SelectSort


//上面的是光盘上的源码的第十章的算法10.1到10.9的部分
//#############################################
