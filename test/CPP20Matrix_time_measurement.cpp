#include<chrono> 
#include <vector>
#include <iostream>
#include "/Users/sahajjain/Desktop/COMPETENCY_TEST/include/CPP20Matrix.hpp"
#include <cassert>

using namespace std;

int main(void) {

	/////////////////////////////////////////////////////////////// INT CPP20Matrix TIME ////////////////////////////////////////////////

	CPP20Matrix<int> b0(50,50,100);
	CPP20Matrix<int> c0(50,50,100);
	
    CPP20Matrix<int> d0(100,100,100);
	CPP20Matrix<int> e0(100,100,100);
    
    CPP20Matrix<int> h0(150,150,100);
	CPP20Matrix<int> i0(150,150,100);

	CPP20Matrix<int> f0(200,200,100);
	CPP20Matrix<int> g0(200,200,100);

	long double int_time_50=0,int_time_100=0,int_time_150=0, int_time_200=0;

	for(int i=0;i<10;i++)
	{
		CPP20Matrix<int> a(50,50);
		chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
		a = (b0+c0);
		chrono::high_resolution_clock::time_point finish = chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = finish - start;
		int_time_50+=elapsed.count();
	}
	int_time_50/=10;

	for(int i=0;i<10;i++)
	{
		CPP20Matrix<int> a(100,100);
		chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
		a = (d0+e0);
		chrono::high_resolution_clock::time_point finish = chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = finish - start;
		int_time_100+=elapsed.count();
	}
	int_time_100/=100;

    for(int i=0;i<10;i++)
	{
		CPP20Matrix<int> a(150,150);
		chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
		a = (h0+i0);
		chrono::high_resolution_clock::time_point finish = chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = finish - start;
		int_time_150+=elapsed.count();
	}
	int_time_150/=10;

	for(int i=0;i<10;i++)
	{
		CPP20Matrix<int> a(200,200);
		chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
		a = f0+g0;
		chrono::high_resolution_clock::time_point finish = chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = finish - start;
		int_time_200+=elapsed.count();
	}
	int_time_200/=10;

	cout<<"INT CPP20Matrix Time measurement \nSIZE - 50 : "<<int_time_50<<" \nSIZE - 100 : "<<int_time_100<<" \nSIZE - 150 : "<<int_time_150<<" \nSIZE - 200 : "<<int_time_200<<"\n";

	/////////////////////////////////////////////////////////////// FLOAT CPP20Matrix TIME ////////////////////////////////////////////////

	CPP20Matrix<float> b1(50,50,100.0);
	CPP20Matrix<float> c1(50,50,100.0);
	
    CPP20Matrix<float> d1(100,100,100.0);
	CPP20Matrix<float> e1(100,100,100.0);
    
    CPP20Matrix<float> h1(150,150,100.0);
	CPP20Matrix<float> i1(150,150,100.0);

	CPP20Matrix<float> f1(200,200,100.0);
	CPP20Matrix<float> g1(200,200,100.0);

	long double float_time_50=0,float_time_100=0,float_time_150=0, float_time_200=0;

	for(int i=0;i<10;i++)
	{
		CPP20Matrix<float> a(50,50);
		chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
		a = (b1+c1);
		chrono::high_resolution_clock::time_point finish = chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = finish - start;
		float_time_50+=elapsed.count();
	}
	float_time_50/=10;

	for(int i=0;i<10;i++)
	{
		CPP20Matrix<float> a(100,100);
		chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
		a = (d1+e1);
		chrono::high_resolution_clock::time_point finish = chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = finish - start;
		float_time_100+=elapsed.count();
	}
	float_time_100/=100;

    for(int i=0;i<10;i++)
	{
		CPP20Matrix<float> a(150,150);
		chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
		a = (h1+i1);
		chrono::high_resolution_clock::time_point finish = chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = finish - start;
		float_time_150+=elapsed.count();
	}
	float_time_150/=10;

	for(int i=0;i<10;i++)
	{
		CPP20Matrix<float> a(200,200);
		chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
		a = f1+g1;
		chrono::high_resolution_clock::time_point finish = chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = finish - start;
		float_time_200+=elapsed.count();
	}
	float_time_200/=10;

	cout<<"FLOAT CPP20Matrix Time measurement \nSIZE - 50 : "<<float_time_50<<" \nSIZE - 100 : "<<float_time_100<<" \nSIZE - 150 : "<<float_time_150<<" \nSIZE - 200 : "<<float_time_200<<"\n";

	/////////////////////////////////////////////////////////////// STRING CPP20Matrix TIME ////////////////////////////////////////////////

	CPP20Matrix<string> b2(50,50,"abcdefghi");
	CPP20Matrix<string> c2(50,50,"abcdefghi");
	
    CPP20Matrix<string> d2(100,100,"abcdefghi");
	CPP20Matrix<string> e2(100,100,"abcdefghi");
    
    CPP20Matrix<string> h2(150,150,"abcdefghi");
	CPP20Matrix<string> i2(150,150,"abcdefghi");

	CPP20Matrix<string> f2(200,200,"abcdefghi");
	CPP20Matrix<string> g2(200,200,"abcdefghi");

	long double string_time_50=0,string_time_100=0,string_time_150=0, string_time_200=0;

	for(int i=0;i<10;i++)
	{
		CPP20Matrix<string> a(50,50);
		chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
		a = (b2+c2);
		chrono::high_resolution_clock::time_point finish = chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = finish - start;
		string_time_50+=elapsed.count();
	}
	string_time_50/=10;

	for(int i=0;i<10;i++)
	{
		CPP20Matrix<string> a(100,100);
		chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
		a = (d2+e2);
		chrono::high_resolution_clock::time_point finish = chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = finish - start;
		string_time_100+=elapsed.count();
	}
	string_time_100/=100;

    for(int i=0;i<10;i++)
	{
		CPP20Matrix<string> a(150,150);
		chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
		a = (h2+i2);
		chrono::high_resolution_clock::time_point finish = chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = finish - start;
		string_time_150+=elapsed.count();
	}
	string_time_150/=10;

	for(int i=0;i<10;i++)
	{
		CPP20Matrix<string> a(200,200);
		chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
		a = f2+g2;
		chrono::high_resolution_clock::time_point finish = chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = finish - start;
		string_time_200+=elapsed.count();
	}
	string_time_200/=10;

	cout<<"STRING CPP20Matrix Time measurement \nSIZE - 50 : "<<string_time_50<<" \nSIZE - 100 : "<<string_time_100<<" \nSIZE - 150 : "<<string_time_150<<" \nSIZE - 200 : "<<string_time_200<<"\n";

   return 0; 
}
