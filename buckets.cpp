#include <string>
#include "buckets.h"
using namespace std;

Buckets::Buckets(int b1, int b2){
  bucket1 = b1;
  bucket2 = b2;
}

string Buckets::returnBucketsInSet(){
  string bucketSet = "(" + to_string(bucket1) + "," + to_string(bucket2) + ")";
  return bucketSet;
}

string Buckets::returnBucketsInSetTwoPlaces(){
  string bucketSet;
  if(bucket1 < 10 && bucket2 < 10)
    bucketSet = "(0" + to_string(bucket1) + ",0" + to_string(bucket2) + ")";
  else if(bucket1 < 10 && bucket2 >= 10)
    bucketSet = "(0" + to_string(bucket1) + "," + to_string(bucket2) + ")";
  else if(bucket1 >= 10 && bucket2 < 10)
    bucketSet = "(" + to_string(bucket1) + ",0" + to_string(bucket2) + ")";
  else
    bucketSet = "(" + to_string(bucket1) + "," + to_string(bucket2) + ")";
  return bucketSet;
}

int Buckets::getBucket1(){
  return bucket1;
}

int Buckets::getBucket2(){
  return bucket2;
}

string Buckets::getBuckets(){
  string buckets;
  buckets = to_string(bucket1) + " " + to_string(bucket2);
  return buckets;
}

string Buckets::getMaxs(){
  string buckets;
  buckets = to_string(bucket1Max) + " " + to_string(bucket2Max);
  return buckets;
}

int Buckets::getMax2(){
  return bucket2Max;
}

string Buckets::returnMax1And2(){
  string max = "(" + to_string(bucket1Max) + "," + to_string(bucket2Max) + ")";
  return max;
}

void Buckets::setBuckets(int b1, int b2){
  bucket1 = b1;
  bucket2 = b2;
}

void Buckets::fillBucket1(){
  bucket1 = bucket1Max;
}
void Buckets::fillBucket2(){
  bucket2 = bucket2Max;
}
void Buckets::emptyBucket1(){
  bucket1 = 0;
}
void Buckets::emptyBucket2(){
  bucket2 = 0;
}
void Buckets::pourFromBucket1ToBucket2(){
  if(bucket2Max - bucket2 >= bucket1) {
    bucket2 += bucket1;
    bucket1 = 0;
  }
  else{
    bucket1 = bucket1 - (bucket2Max - bucket2);
    bucket2 = bucket2Max;
  }

}
void Buckets::pourFromBucket2ToBucket1(){
  if(bucket1Max - bucket1 >= bucket2) {
    bucket1 += bucket2;
    bucket2 = 0;
  }
  else{
    bucket2 = bucket2 - (bucket1Max - bucket1);
    bucket1 = bucket1Max;
  }
}
