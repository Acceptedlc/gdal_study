
#include <iostream>
#include <gdal_priv.h>
#include <cpl_conv.h>

int main() {

  GDALDataset *poDataset;
  GDALAllRegister();
  poDataset = (GDALDataset *) GDALOpen(
          "/Users/lichao/Desktop/project/engine-core-image/test/data/B03_1.jp2",
          GA_ReadOnly);
  if (poDataset == NULL) {
    std::cout<< "fail" << std::endl;
  } else {
    double adfGeoTransform[6];
    double dProjX = 309780.000,dProjY = 3490200.000;


    if( poDataset->GetGeoTransform( adfGeoTransform ) == CE_None )
    {
      double dTemp = adfGeoTransform[1]*adfGeoTransform[5] - adfGeoTransform[2]*adfGeoTransform[4];
      int col = (adfGeoTransform[5]*(dProjX - adfGeoTransform[0]) -
                 adfGeoTransform[2]*(dProjY - adfGeoTransform[3])) / dTemp + 0.5;
      int row =  (adfGeoTransform[1]*(dProjY - adfGeoTransform[3]) -
                  adfGeoTransform[4]*(dProjX - adfGeoTransform[0])) / dTemp + 0.5;
      std::cout<< row << "," << col << std::endl;
    }
  }
}