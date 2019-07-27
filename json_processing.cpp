

#include<iostream>
#include<json/json.h>
#include<json/forwards.h>
#include<json/reader.h>
#include<json/value.h>
#include<fstream>
#include<thread>
#include<vector>
#include<algorithm>
#include<chrono>
using namespace std;
using namespace std::chrono;


void query1(Json::Value var1 = new Json::Value, int N = 0)
{
	double sum = 0;
	for(int i = 0; i<N; i++)
	{
		sum += var1[i]["cost"].asDouble();
	}
	cout<<"The average cost is : "<<sum/100000<<endl;
	delete &var1;
}

void query2(Json::Value var2 = new Json::Value, int N = 0)
{
	double *p;
	double maxCost = 0;
	for(int i = 0; i<N; i++)
	{
		int s = var2[i]["cost_components"].size();

		p = new double[s];
		for(int j = 0; j<s; j++)
		{
			p[j] = var2[i]["cost_components"][j].asDouble();
			if(p[j] > maxCost)
				maxCost = p[j];
		}
	}
	cout<<"The max of cost components is : "<<maxCost<<endl;
	delete &var2;

}

void query3(Json::Value var3 = new Json::Value, int N = 0)
{
	vector<int> cost_id;
	for(int i = 0; i<N; i++)
		if(var3[i]["cost"].asDouble() > 95)
			cost_id.push_back(var3[i]["id"].asInt());

	for(auto i = cost_id.begin(); i!=cost_id.end(); ++i )
		cout<< *i <<",";
	cout<<endl;
	delete &var3;
}

void query4(Json::Value var4 = new Json::Value, int N = 0)
{
	vector<int> cost_components_id;
	double *p;
	for(int i = 0; i<N; i++)
	{
		int s = var4[i]["cost_components"].size();

		p = new double[s];
		for(int j = 0; j<s; j++)
		{
			p[j] = var4[i]["cost_components"][j].asDouble();
		}
		if(*max_element(p, p+s) > 50)
			cost_components_id.push_back(var4[i]["id"].asInt());
		delete[] p;
	}
	delete &var4;
}


int main()
{
	cout<<"Beginning the program"<<endl;
	Json::Reader reader;
	Json::Value root;

	ifstream dataFile("medium.txt", ifstream::binary);


	dataFile>>root;
	int N = root.size() ;

	auto start = high_resolution_clock::now();

	thread th1(query1, root, N);

	thread th2(query2, root, N);

	thread th3(query3, root, N);

	thread th4(query4, root, N);

	th1.join();
	th2.join();
	th3.join();
	th4.join();


	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);

	cout<<"Time taken to process : "<<duration.count()<<" microseconds."<<endl;

	return 0;
}


