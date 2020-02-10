#include<bits/stdc++.h>
using namespace std;
struct point {
   int x, y;
};

int compareX(point p1, point p2) {
   return (p1.x < p2.x);
}

int compareY(point p1, point p2) {
   return (p1.y < p2.y);
}

float distance(point p1, point p2) {   
   return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

float getMinDist(point pts[], int n) {
   float min = 100000;
   for (int i = 0; i < n; i++)
      for (int j = i+1; j < n; j++)
         if (distance(pts[i], pts[j]) < min)
            min = distance(pts[i], pts[j]);
   return min;
}

float min(float a, float b) {
   return (a < b)? a : b;
}

float middleStrip(point strip[], int size, float d) {    
   float min = d;
   for (int i = 0; i < size; i++)
      for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; j++)
         if (distance(strip[i],strip[j]) < min)
            min = distance(strip[i], strip[j]);
   return min;
}

float getClosest(point sort_x[], point sort_y[], int n){
   if (n <= 4)
      return getMinDist(sort_x, n);

   int mid = n/2;
   point mid_point = sort_x[mid];
   point sort_y_left[mid+1];     
   point sort_y_right[n-mid-1];  
   int leftIndex = 0, rightIndex = 0;

   for (int i = 0; i < n; i++) {       
      if (sort_y[i].x <= mid_point.x)
         sort_y_left[leftIndex++] = sort_y[i];
      else
         sort_y_right[rightIndex++] = sort_y[i];
   }

   float leftDist = getClosest(sort_x, sort_y_left, mid);
   float rightDist = getClosest(sort_x + mid, sort_y_right, n-mid);
   float dist = min(leftDist, rightDist);

   point strip[n];      
   int j = 0;

   for (int i = 0; i < n; i++)
      if (abs(sort_y[i].x - mid_point.x) <dist) {
         strip[j] = sort_y[i];
         j++;
      }
   return min(dist, middleStrip(strip, j, dist));    
}

float closestPair(point pts[], int n) {    
   point sort_x[n];
   point sort_y[n];

   for (int i = 0; i < n; i++) {
      sort_x[i] = pts[i];
      sort_y[i] = pts[i];
   }

   sort(sort_x, sort_x+n, compareX);
   sort(sort_y, sort_y+n, compareY);
   return getClosest(sort_x, sort_y, n);
}

int main() {
   point P[] ={{2, 3}, {12, 1}, {5, 50}, {7, 10}, {7, 1}, {-10, 4}, {4,-20}, {2,-8}, {1,-7}, {-1, -6}, {-7, -4}, {10, 2}, {-1, 3}};
   int n = 13;
   cout<< "The minimum distance by brute force " <<getMinDist(P, n)<<endl;
   cout<< "The minimum distance by divide and conquer " <<closestPair(P, n)<<endl;
}
