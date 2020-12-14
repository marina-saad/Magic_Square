#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int FindTheMagicNumber(vector<vector<int> > Square); //for Challenge #1
void CenteredSquareValue(int MagicNum, vector<vector<int>> &Square);
void checkForRows(int R,int MagicNum,vector<vector<int>>&square);
void checkForCols(int C,int MagicNum,vector<vector<int>>&square);
void FillAllWithValues(vector<vector<int>> &Square,int MagicNum);
bool DiagonalCheck(int MagicNum,vector<vector<int>> &square);
bool DiagonalCheck2(int MagicNum,vector<vector<int>> &square);
void Fill(int M,vector<vector<int>> Square1);
int Equation(int Col, vector<vector<int>> &Square); //For Challenge #2
int FindTheMagicNumberFor2ElementsINtheSameRow(vector<vector<int>> &Square); //For Challenge #2 & Challenge #3
void AllCorrners(int M,vector<vector<int>> &Square); //For Challenge #3
void quadratic(long a, signed long b, signed long c, signed long *x1, signed long *x2); //For challenge #4
int FindForFourthChalenge(vector<vector<int>>&Square); //For challenge #4


 //For All Challenges
void Before(vector<vector<int>> Square)
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			cout<<Square[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}
//For Challenge #1 & #2
void Fill(int M,vector<vector<int>> Square1) 
{
	
	//cout<<FindTheMagicNumber(Square1)<<endl;
	//CenteredSquareValue(M,Square1);
	//cout<<Square1[1][1];
	FillAllWithValues(Square1,M);
	bool D1=DiagonalCheck(M,Square1);
	bool D2=DiagonalCheck2(M,Square1);
	if(D1==1 && D2==1) //need to find other way to find new Magic number in case the results are not valid 
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				cout<<Square1[i][j]<<" ";
			}
			cout<<endl;
		}
	}
}


	/*
	Challenge #1 

	12|17|10
	11|- |- 
	- |- |-
	*/
void Challenge1(vector<vector<int>> Square1)
{

	int M=FindTheMagicNumber(Square1);
	CenteredSquareValue(M,Square1);
	//cout<<Square1[1][1];
	Fill(M,Square1);

}
	/*
	Challenge #2 

	- |7 |16
	15|- |- 
	- |- |11
	*/
void Challenge2(vector<vector<int>> &Square1)
{

	int M=FindTheMagicNumberFor2ElementsINtheSameRow(Square1);
	CenteredSquareValue(M,Square1);

	Fill(M,Square1);

}

	/*
	Challenge #3 

	- |- |-
	31|- |15 
	- |41|-
	*/
void Challenge3(vector<vector<int>> &Square1)
{

	int M=FindTheMagicNumberFor2ElementsINtheSameRow(Square1);
	CenteredSquareValue(M,Square1);
		for(int i=0;i<3;i++)
	{
		checkForCols(i,M,Square1);
	}
	AllCorrners(M,Square1);
	bool D1=DiagonalCheck(M,Square1);
	bool D2=DiagonalCheck2(M,Square1);
	if(D1==1 && D2==1) //need to find other way to find new Magic number in case the results are not valid 
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				cout<<Square1[i][j]<<" ";
			}
			cout<<endl;
		}
	}
}
/*
	Challenge #4

	- |- |-
	- |- |18
	- |28 |-


	for this challenge I needed to follow a rule says that if we multiply three nums in each row together and add the three 
	products we get the same total as when we multiply the three nums in each column together and add the three products

	based on this square
	X+N  |X-M-N |X+M
	X-N+M|   X  |18
	X-M  |  28  |X-N

	by solving manually these equations
	N-M=18^2-X
	N+M=28^2-X

	N=554-X  and by substituting in M=28^2-X-N then M=230

	based on what mentioned in these links
	https://www.mathpages.com/home/kmath417.htm
	https://nrich.maths.org/1376


	*/

void Challenge4(vector<vector<int>>&Square)
{
	Square[0][0]=(Square[1][2]+Square[2][1])/2;
	//cout<<Square[0][0];
	int M= FindForFourthChalenge(Square);
	Square[1][1]=M/3;
	for(int i=0;i<3;i++)
	{
		checkForCols(i,M,Square);
	}
	for(int i=0;i<3;i++)
	{
		checkForRows(i,M,Square);
	}
		for(int i=0;i<3;i++)
	{
		checkForCols(i,M,Square);
	}
	bool D1=DiagonalCheck(M,Square);
	bool D2=DiagonalCheck2(M,Square);
	if(D1==1 && D2==1) //need to find other way to find new Magic number in case the results are not valid 
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				cout<<Square[i][j]<<" ";
			}
			cout<<endl;
		}
	}

}
int main()
{

	vector<vector<int>> Square1(3, vector<int>(3));
	
	Square1[0][0]=12,Square1[0][1]=17,Square1[0][2]=10;
	Square1[1][0]=11;
	cout<<"Challenge #1: "<<endl;
	cout<<"Before"<<endl;
	Before(Square1);
	cout<<"After"<<endl;
	Challenge1(Square1);
	
	cout<<endl;
	vector<vector<int>> Square2(3, vector<int>(3));
	Square2[0][1]=7,Square2[0][2]=16,Square2[1][0]=15;
	Square2[2][2]=11;
	cout<<"Challenge #2: "<<endl;
	cout<<"Before"<<endl;
	Before(Square2);
	cout<<"After"<<endl;
	Challenge2(Square2);
	//cout<<Square2[2][2]<<endl;
	cout<<endl;
	vector<vector<int>> Square3(3, vector<int>(3));
	Square3[1][0]=31, Square3[1][2]=15;
	Square3[2][1]=41;
	cout<<"Challenge #3: "<<endl;
	cout<<"Before"<<endl;
	Before(Square3);
	cout<<"After"<<endl;
	Challenge3(Square3);
	cout<<endl;
	//cout<<FindTheMagicNumberFor2ElementsINtheSameRow(Square3)<<endl;

	//cout<<endl<<endl<<FindTheMagicNumberFor2ElementsINtheSameRow(Square2)<<endl<<Square2[1][1]<<endl;
//	cout<<Square1[0][0]<<Square1[0][1]<<Square1[0][2]<<endl;
	/*
	the result for challenge #4 should be: 
	23|30|34
	40|29|18
	24|28|35
	*/
	vector<vector<int>> Square4(3, vector<int>(3));
	Square4[1][2]=18;
	Square4[2][1]=28;
	cout<<"Challenge #4: "<<endl;
	cout<<"Before"<<endl;
	Before(Square4);
	cout<<"After"<<endl;
	Challenge4(Square4);
	
	//Before(Square4);
	return 0;
}

int FindTheMagicNumber(vector<vector<int> > Square)
{
	vector<int> sum;
	for(int i=0;i<3;i++)   //need to check that all columns in the same row have values and all rows in the same column have values
	{
		int R=0,C=0;
		for(int j=0;j<3;)
		{
			if(Square[i][j]==0)
			{
				j++;
			}
			else
			{
				R+=Square[i][j];
				C+=Square[j][i];
				j++;
			}
		}
		sum.push_back(R);
		sum.push_back(C);
		R=0;
		C=0;
	}
	int Max=0;
	for(int i=0;i<sum.size();i++)
	{
		if(sum[i]>Max)
			Max=sum[i];
		//cout<<sum[i]<<endl;
	}
	return Max;
}
void CenteredSquareValue(int MagicNum, vector<vector<int>> &Square)
{
	Square[1][1]=MagicNum/3;
}
void checkForRows(int R,int MagicNum,vector<vector<int>>&square)
{
	int a=square[R][0];
	int b=square[R][1];
	int c=square[R][2];

	if(a==0 && b!=0 && c!=0)
	{
		square[R][0]=MagicNum-(b+c);
	}
	else if(a!=0 && b==0 && c!=0)
	{
		square[R][1]=MagicNum-(a+c);
	}
	else if(a!=0 && b!=0 && c==0)
	{
		square[R][2]=MagicNum-(a+b);
	}
}
void checkForCols(int C,int MagicNum,vector<vector<int>>&square)
{
	int a=square[0][C];
	int b=square[1][C];
	int c=square[2][C];
	
	if(a==0 && b!=0 && c!=0)
	{
		square[0][C]=MagicNum-(b+c);
	}
	else if(a!=0 && b==0 && c!=0)
	{
		square[1][C]=MagicNum-(a+c);
	}
	else if(a!=0 && b!=0 && c==0)
	{
		square[2][C]=MagicNum-(a+b);
	}
}
void FillAllWithValues(vector<vector<int>> &Square,int MagicNum)
{
	for(int i=0;i<3;i++)
	{
		checkForRows(i,MagicNum,Square);
		checkForCols(i,MagicNum,Square);
	}
}

bool DiagonalCheck(int MagicNum,vector<vector<int>> &square)
{
	int sum=0;
	for(int i=0;i<3;i++)
	{
		sum+=square[i][i];
	}
	if(sum!=MagicNum)
		return 0;
	else return 1;
}
bool DiagonalCheck2(int MagicNum,vector<vector<int>> &square)
{
	int sum=0;
	for(int i=0;i<3;i++)
	{
		sum+=square[2-i][i];
	}
	if(sum!=MagicNum)
		return 0;
	else return 1;
}
// find the value using an equation having an only variable 
int Equation(int Col, vector<vector<int>> &Square)
{
	int Y=0;
	for(int i=0;i<3;i=i+2)
	{
		//cout<<i<<endl;
		if(Square[i][Col]!=0)
		{
			Y+=Square[i][Col];
			//cout<<endl<<Y<<endl;
		}
	}
	return Y;
}
int FindTheMagicNumberFor2ElementsINtheSameRow(vector<vector<int>> &Square)
{
	int MagicNum;
	int Col=-1;
	int X=0;
	int Y;
	for(int i=0;i<3;i=i+2)
	{
		//cout<<"IN";
		if(Square[1][1]==0)
		{
			//cout<<"1"<<endl;
			if(Square[1][i]==0)
			{
				Col=i;
				//cout<<"2"<<endl;
			}
			else{
				//cout<<"3"<<endl;
				X+=Square[1][i];
			}

			if(Col!=-1)
			{
				//cout<<"4"<<endl;
				Y=Equation(Col,Square);
			}
		}
		else
		{
			//cout<<"5"<<endl;
			MagicNum=Square[1][1]*3;
		}
	}
	//X=X+X/3+(X-Y);
	if(Col==-1)
	{
		//cout<<"IN"<<endl;
		MagicNum=(3*X)/2;
	}
	else
	{
		//cout<<"6"<<endl;
		MagicNum=(3*Y)-(3*X);
	}
	return MagicNum;
}
void AllCorrners(int M,vector<vector<int>> &Square)
{
	int dia,col,row;
	dia=M-Square[1][1];
	col=M-Square[1][2];
	row=M-Square[0][1];
	Square[0][0]=(dia-col+row)/2;
	Square[0][2]=(row-dia+col)/2;
	Square[2][2]=(col-row+dia)/2;
	Square[2][0]=M-(Square[0][0]+Square[1][0]);
}
void quadratic(long a, signed long b, signed long c, signed long *x1, signed long *x2)
{
	int realPart, imaginaryPart;
	long long discriminant =  34463030140;
      if (discriminant > 0) {
		  *x1 =ceil(-1*b + sqrt(discriminant) / (2*a));
		  *x2 =ceil( (-1*b - sqrt(discriminant)) / (2*a));
	  }
	  else if (discriminant == 0) {

          *x1 = (-b + sqrt(discriminant)) / (2*a);
	  }
	  else {
         realPart = (float) -b/(2*a);
		 imaginaryPart =sqrt(-discriminant)/(2*a);
	  }

}
int FindForFourthChalenge(vector<vector<int>>&Square)
{
	int MagicNum=23;
	signed long a=230,b=-156070,c=-10983897,n1=0,n2=0;
	quadratic(a,b,c,&n1,&n2);
	if(n1<n2)
	{
		MagicNum-= n1;
		//cout<<"yyyy"<<endl;
	}
	else
		MagicNum-=n2;
	return MagicNum;
}