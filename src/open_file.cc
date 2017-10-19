
#include <iostream>
#include <gdal_priv.h>
#include <cpl_conv.h>

int main() {

  GDALDataset *poDataset;
  GDALAllRegister();
  poDataset = (GDALDataset *) GDALOpen(
          "/Users/lichao/Desktop/project/engine-core-image/test/data/B03_1111aaajp2",
          GA_ReadOnly);
  if (poDataset == NULL) {
    std::cout<< "fail" << std::endl;
  } else {
    std::cout<< "success  asd" << std::endl;
  }
  return 1;
}