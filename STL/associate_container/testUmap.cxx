#include <unordered_map>
#include <iostream>


#include <string>


int main()
{
   std::unordered_map<int, int> mMap(1000);
   

   for ( int i = 0; i < 100; ++i) {
      mMap[i] = i;
   }

   std::cout << mMap.bucket_count() << std::endl;
   std::cout << mMap.size() << std::endl;

    return 0;
}
