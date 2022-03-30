#include<bits/stdc++.h>
#include"solver.h"
using namespace std;

string testDirPath = "Week-1/testCases";
string resFilePath = "Week-1/result/cpp17-result.txt";

const int maxn = int(1e6);
int n;
int arr[maxn]; 

void run(vector<string> paths, string s){
    ofstream resfile;
    resfile.open(resFilePath, ios::app);
    resfile<<"\t"<<s<<"\n";
    resfile.close();
    for(auto path: paths){
        if(path.find(s)==-1) continue;
        ifstream testfile;
        testfile.open(path);
        testfile>>n;
        for( int i=0; i<n; ++i ) testfile>>arr[i];
        testfile.close();

        auto resbf = bruteForce(arr, n);
        auto resbfi = bruteForceWithImprovement(arr, n);
        auto resdp = dynamicProgramming(arr, n);

        string filename = path.substr(path.find_last_of("/\\") + 1);

        resfile.open(resFilePath, ios::app);
        resfile<<"\t\t"<<filename<<"\n";
        resfile<<"\t\t\tbrute force:                    "<<resbf.first<<"\n";
        resfile<<"\t\t\tbrute force with improvement:   "<<resbfi.first<<"\n";
        resfile<<"\t\t\tdynamic programming:            "<<resdp.first<<"\n";
        if(resbf.second==resbfi.second && resbf.second==resdp.second)
            resfile<<"\t\t\t\tconsistent result\n";
        resfile.close();
    }
}

int main()
{
    vector<string> testCasesPath;

    for (const auto &entry: filesystem::directory_iterator(testDirPath)){
        testCasesPath.push_back(entry.path());
    }
    sort(testCasesPath.begin(), testCasesPath.end());

    ofstream resfile;
    resfile.open(resFilePath, ios::app);
    time_t now = time(0);
    char* dt = ctime(&now);
    resfile<<dt;
    resfile<<"\tCompiled with g++ -stdc++2a\n";
    resfile.close();

    run(testCasesPath, "1e3");
    run(testCasesPath, "1e4");
    run(testCasesPath, "1e5");
    run(testCasesPath, "1e6");

    resfile.open(resFilePath, ios::app);
    resfile.close();
}