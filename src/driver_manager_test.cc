
#include <iostream>
#include <gdal_priv.h>
#include <cpl_conv.h>

int main() {

  GDALDataset *poDataset;
  GDALAllRegister();
  int a = GetGDALDriverManager()->GetDriverCount();
  std::cout << a << std::endl;
  GDALDriver* d1 = GetGDALDriverManager()->GetDriverByName("JP2ECW");
  if(d1==nullptr) {
    std::cout << "no JP2ECW" << std::endl;
  } else {
    std::cout << "get JP2ECW" << std::endl;
  }

  GDALDriver* d2 = GetGDALDriverManager()->GetDriverByName("MEM");
  if(d2==nullptr) {
    std::cout << "no MEM" << std::endl;
  } else {
    std::cout << "get MEM" << std::endl;
  }

  return 1;
}