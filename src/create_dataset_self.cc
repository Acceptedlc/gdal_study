//
// Created by lichao on 2018/1/4.
//

#include <iostream>
#include <gdal_priv.h>

int main() {
  GDALAllRegister();
  GDALDriver *poDriver;
  const char *pszFormat ="GTiff";
  poDriver = GetGDALDriverManager()->GetDriverByName(pszFormat);

  if(poDriver == nullptr) {
    return 1;
  }
  GDALDataset *OutDs;
  OutDs = poDriver->Create( "/Users/lichao/Desktop/study/gdal_study/create_dataset_selt_result.tiff", 512, 512, 1, GDT_Byte,
                            nullptr);
  double adfGeoTransform[6] = { 118.487, 0.000125068, 0, 43.000, 0, -8.79695e-05};
  OutDs->SetGeoTransform( adfGeoTransform );
  OutDs->SetProjection("GEOGCS[\"WGS 84\",DATUM[\"WGS_1984\",SPHEROID[\"WGS 84\",6378137,298.257223563,AUTHORITY[\"EPSG\",\"7030\"]],AUTHORITY[\"EPSG\",\"6326\"]],PRIMEM[\"Greenwich\",0],UNIT[\"degree\",0.0174532925199433],AUTHORITY[\"EPSG\",\"4326\"]]");
//  118.487,43.000



  float * outData = new float [512*512];
  for(int i = 0;i < 512; i++) {
    for(int j = 0;j < 512; j++) {
      *(outData + i * 512 + j) = 0.1;
    }
  }


  GDALRasterBand *outBand = OutDs->GetRasterBand(1);

  ::CPLErr err = outBand->RasterIO(GF_Write,0,0,512,512,outData,512,512,GDT_Float32,0,0);
  std::cout << err << std::endl;
  GDALClose(OutDs);

  return 1;
}
