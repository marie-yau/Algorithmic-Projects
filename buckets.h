#include <string>
/* Class that models every situation for given two buckets.
 *
 */
using namespace std;

class Buckets{
private:
  int bucket1Max = 11;
  int bucket2Max = 18;
  int bucket1;
  int bucket2;

public:
  Buckets* fill1;
  Buckets* fill2;
  Buckets* empty1;
  Buckets* empty2;
  Buckets* pourFrom1To2;
  Buckets* pourFrom2To1;
  Buckets* previous;

  //constructors
  Buckets();
  Buckets(int b1, int b2);
  //return buckets' values in formatted string
  string returnBucketsInSet();
  string returnBucketsInSetTwoPlaces();
  //pouring
  void fillBucket1();
  void fillBucket2();
  void emptyBucket1();
  void emptyBucket2();
  void pourFromBucket1ToBucket2();
  void pourFromBucket2ToBucket1();
  //setters and setters
  void setBuckets(int b1, int b2);
  int getBucket1();
  int getBucket2();
  string getBuckets();
  string getMaxs();
  int getMax2();
  string returnMax1And2();
};