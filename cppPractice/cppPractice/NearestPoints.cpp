#include"Header.h"

using namespace std;

Point::Point(int n, int m): x(n), y(m) 
{
	
}



void Point::EuclideanDist(Point p0)
{
	dist = sqrt((x - p0.x)*(x - p0.x) + (y - p0.y)*(y - p0.y));

}

void NearestPoints(vector<Point> &points, Point &origin, int k)
{

	vector<Point>::iterator itr;	// iterator to travers list of points
	//map<int,Point> dist_vec;	// vector to store distances of points from origin
	priority_queue<Point,vector<Point>, Compare> p_srt;
	//claculate distances from origin
	for (itr = points.begin(); itr != points.end(); ++itr)
	{
		Point temp = *itr;
		temp.EuclideanDist(origin);
		p_srt.push(temp);
	}
	for (int i=0;i<k;++i)
	{
		Point p = p_srt.top();
		p_srt.pop();
		cout << p.x << " " << p.y << "\t d= " << p.dist << endl;
	}
	

	

}