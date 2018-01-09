#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <eigen3/Eigen/Dense>
#include <sstream>
#include <vector>
#include "OctomapConstants.hpp"

using namespace std;

int main()
{
 int rows=2;
 int columns=6;

 std::vector<double> v;

 Eigen::Vector3d robotPose;
 Eigen::Matrix3Xd sensorPos;
 Eigen::Matrix3Xd laserData;
 Eigen::MatrixXd robotSLAM = Eigen::MatrixXd::Identity(154, 6);


int i;
std::string s1;
std::string robottext;
std::string pointstext;
std::string Result;

for(i=1;i<=77;++i)
	if (i<=9)
		{
		 std::string s1 = "data/scan_00";
		 ostringstream convert;
		 convert << i;
		 Result = convert.str();
		 robottext = s1 + Result +"_robotPoses.dat";
		 pointstext = s1 + Result +"_points.dat";

		 std::cout << robottext << '\n';
		 std::cout << pointstext << '\n';

		 ifstream file(robottext.c_str()); //opened the text file
		 if(file.is_open())
		 {
		 	while(getline(file,robottext))
		 	//while(file >> robotSLAM(i-1,0) >> robotSLAM(i-1,1) >> robotSLAM(i-1,2) >> robotSLAM(i-1,3) >> robotSLAM(i-1,4) >> robotSLAM(i-1,5) )
		 	{
		 		//std::cout << robottext << '\n';
		 		istringstream is( robottext );
    			double n;
    			while( is >> n ) 
    			{
        			v.push_back( n );
    			}
    			int vectorSize=v.size();
    			cout << vectorSize << endl;

		 	}
		 	file.close();


		 }
		 else
		 {
		 	std::cout << "file cannot be opened" << '\n';
		 }
		 // ifstream file1(pointstext.c_str());
		 // if(file1.is_open())
		 // {
		 // 	while(getline(file1,pointstext))
		 // 	{
		 // 		std::cout << pointstext << '\n';
		 // 	}
		 // 	file1.close();
		 // }
		 // else
		 // {
		 // 	std::cout << "file cannot be opened" << '\n';
		 // }

		}

	else
		{
		 std::string s1 = "data/scan_0";
		 ostringstream convert;
		 convert << i;
		 Result = convert.str();
		 robottext = s1 + Result +"_robotPoses.dat";
		 pointstext = s1 + Result +"_points.dat";
		 std::cout << robottext << '\n';
		 std::cout << pointstext << '\n';
		}
return 0;


}


