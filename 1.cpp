/*
 * 1.cpp

 *
 *  Created on: 2015年7月16日
 *      Author: root
 */
/*
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n ;
	int buf[100];

	while (scanf("%d" , &n) != EOF  ){
	for (int i = 0 ; i < n ; i++) {
		scanf("%d" , &buf[i]);//这里的 %d一定不能有空格，不然就要多读一个数才可以
	}
	for (int i = 0 ; i < n  ; i++){
		for (int j = 0 ; j < n - 1 - i ; j ++){
			if(buf[j] > buf[j+1]){
				int temp = buf[j];
				buf[j] = buf[j+1];
				buf[j+1] = temp;
			}
		}
	}

	for ( int i = 0; i < n ; i++) {
		printf("%d ", buf[i]);//输出是按照要求进行输出的。
	}
	printf("\n");
    }
  return 0;
}


*/
/*
 *
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n ;
	int buf[100];

	while (scanf("%d" , &n) != EOF  ){
	for (int i = 0 ; i < n ; i++) {
		scanf("%d" , &buf[i]);//这里的 %d一定不能有空格，不然就要多读一个数才可以
	}
	sort(buf , buf + n);//使用快排是从小到大的

	for ( int i = 0; i < n ; i++) {
		printf("%d ", buf[i]);//输出是按照要求进行输出的。
	}
	printf("\n");
    }
  return 0;
}

*/

/*
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

bool cmp(int x , int y ){
	return x > y;
}


int main(){
	int n ;
	int buf[100];
    vector<int>buff;
    int temp;
	while (scanf("%d" , &n) != EOF  ){
	for (int i = 0 ; i < n ; i++) {
		scanf("%d" , &temp);//这里的 %d一定不能有空格，不然就要多读一个数才可以

		buff.push_back(temp);  //scanf  读取后压入vector中
	}
	//using vector

	sort(buff.begin() , buff.end() , cmp);//使用快排是从小到大的  ，使用begin 和end

	for ( int i = 0; i < n ; i++) {
		printf("%d ", buf[i]);//输出是按照要求进行输出的。
	}
	printf("\n");
    }


	for(vector<int>::iterator si = buff.begin() ; si != buff.end() ; si++){  //这里的类型需要注意，是指针的，使用了iterator
		cout << *si << " ";
	}
	cout << endl;  //输出的方式需要注意
	}


	for(vector<int>::iterator si = buff.begin() ; si != buff.end() ; si++){
		//输出是很纠结的，看后面的情况
	}
  return 0;
}

*/
/*
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>


using namespace std;

struct E {
	char name[200];  //使用char  ，尽量不要用string
	int   age ;
	int   score;

}buf[1000];

bool cmp(E x  , E y){
	if(x.score  != y.score)  return x.score < y.score;
	if(strcmp(x.name , y.name)  != 0 )   return strcmp(x.name , y.name) < 0;  //strcmp需要使用临时变量完成基本的任务
	//if(x.age != y.age)  return  x.age < y.age;
	//这里需要使用else ， 防止出现没有热突然return返回的情况。
	else return x.age < y.age;
}
	int main(){
		int N ;
		//INput
		while(scanf("%d" , &N) != EOF){
			for(int i = 0 ;i < N; i++){
				scanf("%s %d %d" , &buf[i].name , &buf[i].age , &buf[i].score );
			//	if(buf[i] > 100 || buf[i] < 0) 无需判断是否分数是存在合理的。
			}
			sort(buf , buf+N , cmp);
			for(int i = 0 ;i < N ; i++){
				printf("%s %d %d\n" , buf[i].name , buf[i].age , buf[i].score);
			}

		}


		return 0;
	}

*/


//对于闰年，使用 ==0的方式就可以了。
/*

#include <iostream>
#include <stdio.h>

#define IsYeap(x)   x%100 != 0 && x%4 == 0 || x%400 == 0  ? 1 : 0

int dayOfMonth[13][2] = {
		0,0,
		31,31,
		28,29,
		31,31,
		30,30,
		31,31,
		30,30,
		31,31,
		31,31,
		30,30,
		31,31,
		30,30,
		31,31
};

struct Date {
	int year ;
	int month;
	int day;
	void nextDay(){//可以调用这个API将后一天的天数求出来
		day ++;
		if(day > dayOfMonth[month][IsYeap(year)]) {
			day =1 ;
			month ++ ;
			if(month > 12 ) {
				month = 1;
				year ++;

			}
		}
	}
};


int buf[5000][13][32];//这个值的位置在int main的外面，这里主要是为了节省空间

int Abs(int x) {
	return x < 0 ? -x : x;
}

int main(){  // int main 先写，理清思路，后面添加前面的东西。
	Date tmp;
	int count = 0;
	tmp.day = 1;
	tmp.month = 1;
	tmp.year = 0;
	//初始化完毕

	while (tmp.year != 5001){
		buf[tmp.year][tmp.month][tmp.day]  = count ;
		tmp.nextDay();
		count ++;
	}
	//上面的预处理完毕了

	int d1 ,m1 , y1 ;
	int d2 , m2 , y2 ;
	while (scanf("%4d%2d%2d",&d1,&m1,&y1) != EOF ){
		scanf("%4d%2d%2d",&d2,&m2,&y2);
		printf("%d\n" , Abs(buf[d1][m1][y1] - buf[d2][m2][y2]));
	}
	return 0;
}

*/
/* 例题 2.5
 * 注意使用的N == 0
 */
/*

#include <stdio.h>

using namespace std;

int main(){
	int N;
	int count[101]={0};
	int tmp;
	int tar;

	while(scanf("%d" , &N) != EOF && N != 0){  //这里使用并集较好，直接夹在后面，先是scanf读取，再用 N
		for(int i = 0 ; i < N ; i++){
			scanf("%d" , &tmp);
			count[tmp]++;
		}
		scanf("%d", &tar);
		printf("%d\n" , count[tar]);
	}
	return 0;
}

*/

//C++ 支持 <=  符号哦～～～～
//看题目，要求是  各不相同  ， 且区间的是确定的。
//代码2.9先不做啊啊啊

//先完成排版再完成输出，  我们看如果是字符的话，将其转换为矩阵，再在最后输出，可以完成一副图画。

//千万数量级是不能被看到的，需要额外选用合适的算法查到

/*-----------------------------------------------------------------------------------------------*/

/*  //这一次是没有写出来的，，需要你自己熟练后重新复习一遍。可能和书上的不同，这里小心了。代码  3.2
#include <stack>
#include <stdio.h>
#include <string.h>

using namespace std;

char str[220] ;
int mat[][5] = {
		1,0,0,0,0,
		1,0,0,0,0,
		1,0,0,0,0,
		1,1,1,0,0,
		1,1,1,0,0,

};

stack<int> op;
stack<double> in;

void getOp(bool &reto , int &retn , int &i){
	if(i == 0 && op.empty() == true){
		reto = true;
		retn = 0;
		return  ;
	}
	if(str[i] == 0 ){
		reto = true;
		retn = 0;
		return ;

	}
	if(str[i] >= '0' && str[i] <= '9'){
		reto = false;
	}else{
		reto = true ;
		if(str[i] == '+' ){
			retn = 1;
		}else if (str[i] == '-'){
			retn = 2;
		}else if (str[i] == '*'){
			retn = 3;
		}else if (str[i] == '/'){
			retn = 4;
		}// no "else"
		i += 2;
		return ;

	}
	retn = 0;
	for(;str[i] != ' ' && str[i] != 0; i++){
		retn *= 10;
		retn += str[i] - '0';
	}
	if(str[i] == ' ')  i++;
	return ;
}

int main(){
	while(gets(str)) {
	//  while(fgets(str,210,stdin))  {
		if(str[0] == '0' && str[1] == 0 ) break;
		bool retop;
		int retnum;
		int idx = 0;

		while(!op.empty())  op.pop();
		while(!in.empty())  in.pop();
		while(true){
			getOp(retop ,retnum ,idx);
			if(retop == false){
				in.push((double)retnum);
			}
			else {
				double tmp;
				if(op.empty() == true  || mat[retnum][op.top()] == 1) {
					op.push(retnum);
				}
				else {
					while(mat[retnum][op.top()] ==  0  ){
						int ret = op.top();
						op.pop();
						double b = in.top();
						in.pop();
						double a = in.top();
						in.pop();
						if(ret == 1) tmp = a + b;
						else if (ret == 2) tmp = a - b;
						else if (ret == 3) tmp = a * b;
						//else if (ret == 4) tmp = a / b;
						//else tmp = 99999;
						else tmp = a / b;
						in.push(tmp);
					}
					op.push(retnum);
				}
			}
			if(op.size() == 2  && op.top() == 0)  break;
		}
		printf("%.2f\n" , in.top());
	}
	return 0;
}

*/

//Haffman Tree using priority_queue
// Haffman 树比较简单， 这里快速记忆下
/*
#include<queue>
#include<stdio.h>
using namespace std;

priority_queue<int , vector<int> , greater<int> > Q;  //这里查书

int main() {
	int n ;
	while (scanf("%d" , &n)  != EOF) {
		while(Q.empty() == false)  Q.pop();   //这个和赋值一样，需要放在前面。进行相关的解释

		for (int i = 0 ; i < n ; i++){
			int temp;
			scanf("%d" , &temp);
			Q.push(temp);
		}
		//完全放进去之后，由于是小顶堆，于是我们直接进行了排序。
		int ans = 0 ;
		while (Q.size() > 1){
			int  a = Q.top();
			Q.pop();
			int b = Q.top();
			Q.pop();
			ans += a + b;
			Q.push(a+b);
		}
		printf("%d\n" , ans);
	}
	return  0;
}

*/
/*

#include<stdio.h>
#include<string.h>

struct Node {
	Node *lchild;
	Node *rchild;
	char c;
}Tree[50];  // Node Tree[50];

int loc ; //这里的函数需要使用，所以哦那个全局变量。

Node *creat(){
	Tree[loc].lchild = Tree[loc].rchild = NULL;
	return &Tree[loc++];
}

char str1[30] , str2[30];
void postOrder(Node *T){
	if(T -> lchild != NULL)
		postOrder(T -> lchild);
	if(T -> rchild != NULL)
		postOrder(T -> rchild);
	printf("%c" , T -> c);
	// no return
}

Node * build(int s1 , int e1 , int s2  , int e2 ) {

}



int main() {
	while (scanf("%s" , str1)  != EOF ) {
		scanf("%s" , str2 );
		loc = 0 ;  //之前放在起始变量
		int L1 = strlen(str1);
		int L2 = strlen(str2);
		Node *T = build( 0 , L1 - 1 , 0 , L2 - 1);
		postOrder(T);
		printf("\n");
	}
	return 0;
}

*/

//题目1003 ， 查看方式，目前方式错误
/*
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
int main() {
	char str1[100] ,str2[100] ;
	int v1=0,v2=0 ;  //p判断逗号
	int f1=0,f2=0 ; //f 判断符号正负
	int length1,length2 ; //length
	int add; //进位数
	while(scanf("%s %s" , str1 , str2 ) != EOF){
		if(str1[0] == "-") f1 = 1 ;
		if(str2[0] == "-") f2 = 1 ;// f
		for(int i = 0 ; i < strlen(str1) ; ++i){
			if(str1[i] == ",") ++v1;
		}
		for(int i = 0 ; i < strlen(str2) ; ++i){
			if(str2[i] == ",")  ++v2;  //v1 v2 finished
		}

		//直接去掉逗号不就是了。 。。先把特殊符号去掉
		if(f1 = 1 ) {
			for(int i = 1 ; i < strlen(str1) ; i++){
				str1[i-1] = str1[i];
			}
		}
		if(f2 = 1 ) {
					for(int i = 1 ; i < strlen(str2) ; i++){
						str2[i-1] = str2[i];
					}
				}
		if(v1 != 0) {
			for( int j = v1 ; j > 0  ; j--)
				for(int i = 4*v1; i < strlen(str1) ; i++){
					str1[i-1] = str1[i];
				}
		}
		if(v2 != 0) {
				for( int j = v2 ; j > 0  ; j--)
					for(int i = 4*v2; i < strlen(str2) ; i++){
						str2[i-1] = str2[i];
				}
			}
		printf("%s\n" , str1);
		printf("%s\n" , str2);


	}
	return 0 ;
}

*/


//题目1202


/*#include<stdio.h>
#include<algorithm>

using namespace std;

int main() {
	int n ;
	int arr[100];

	while(scanf("%d", &n)  != EOF){
		for(int i = 0 ; i < n ; i++) {
			scanf("%d" , &arr[i]);
		}
		sort(arr , arr + n);
		for(int i = 0 ; i < n ; i++){
			printf("%d " , arr[i]);
		}
		printf("\n");
	}
	return 0 ;
}

*/

/*
#include<stdio.h>
#include<algorithm>

using namespace std;

int main() {
	int n ;
	int arr[100];

	while(scanf("%d", &n)  != EOF){
		for(int i = 0 ; i < n ; i++) {
			scanf("%d" , &arr[i]);
		}
		//sort(arr , arr + n);
		for(int j = 0 ; j < n ; ++j )
			for(int i = 0 ; i < n - 1 - j ; ++i){
				if(arr[i] > arr[i + 1]) {
					int tmp = arr[i];
					arr[i] = arr[i+1];
					arr[i + 1] = tmp;
				}
			}



		for(int i = 0 ; i < n ; i++){
			printf("%d " , arr[i]);
		}
		printf("\n");
	}
	return 0 ;
}

*/

//1061
/*
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<stdlib.h>

using namespace std;
//结构体和cmp函数该放在main之外。
typedef struct student{
//	char name[100];
char name[101];
int age;
int score;
};
student stu[1000];

bool cmp(student a , student b){
	if(a.score != b.score)  return a.score < b.score ;
	int tmp = strcmp(a.name , b.name);
	//if(tmp < 0 )  return a.name
	if(tmp != 0 )  return tmp < 0 ;  //两个if
	else return a.age < b.age;
}

int main() {
	int n ;


	while(scanf("%d" , &n ) != EOF){
		for(int i = 0 ; i < n ; ++i){
		//scanf("%s %d %d" , &stu[i].name, &stu[i].age , &stu[i].score);
			//这里的name部分是属于指针的，不能加上&。
		scanf("%s%d%d" ,stu[i].name , &stu[i].age , &stu[i].score);

		}
		//sort 下的compare方式  sort(stu.score , stu.score+n);
		sort (stu,stu+n , cmp);   // cmp 和其对应的类型相关
		for(int i = 0 ; i < n ; i++){
			printf("%s %d %d\n" , stu[i].name , stu[i].age , stu[i].score);
		}

	}

	return 0 ;
}
*/

//1185  需要开始自己做了。
/*
#include<stdio.h>
#include<algorithm>

using namespace std;

int main() {
	int n ;
	int arr[1000]= {0};

	while(scanf("%d" , &n) != EOF){
		//特殊终止方式
		for(int i  = 0 ; i < n ; i++)
			scanf("%d" ,&arr[i]);
		if(n == 1){ //这里是== 1 ，需要注意不和逻辑混淆
			printf("%d\n" , arr[0] );
		//	int tmp = -1;
		//	printf("%d\n" , tmp);
			//格式错误，这里的-1可能表示特殊含义？？
	        printf("-1\n");
		}
		else{
			sort(arr , arr+n );
			printf("%d\n" , arr[n-1]);
			sort(arr , arr+n-1);
			for(int i = 0 ; i < n-1 ; i++)
				printf("%d ", arr[i]);
			printf("\n");
		}
	}

	return 0 ;
}

*/


#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct Sales_item {
		int number ;
		bool IsExport ;
		char Type[101] ;
		float price;
	}buf;

int main() {



	 int num;
	 scanf("%d " , &num);
	for(int i = 0 ; i < num ; i++ ){
//----------
	scanf("%d %b %s %f" , &buf.number ,&buf.IsExport, buf.Type , &buf.price ) ;
		int tax = 0;
		int sum = 0;

		if(buf.Type == "book" || buf.Type == "chocolate" || buf.Type == "pill")
		{
			if(buf.IsExport == true )
				tax = buf.number * buf.price * 0.05 ;
			else if(buf.IsExport == false )
				tax = buf.number * buf.price * 0;
			else
				printf("Error! IsExport1");

		}
		else if(buf.Type == "CD" || buf.Type == "perfume" )
		{
			if(buf.IsExport == 1 )
				tax = buf.number * buf.price * 0.15 ;
			else if(buf.IsExport == 0 )
				tax = buf.number * buf.price * 0.10;
			else
				printf("Error! IsExport2");
		}

		sum = buf.number * buf.price + tax ;

		//output
		printf("%d %b %s %6.2f\n",buf.number ,buf.IsExport, buf.Type , sum );


	//end while

	}
	return 0;

}
























