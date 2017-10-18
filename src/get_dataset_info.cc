
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

//    printf( "Driver: %s/%s\n",
//            poDataset->GetDriver()->GetDescription(),
//            poDataset->GetDriver()->GetMetadataItem( GDAL_DMD_LONGNAME ) );
//    std::cout<<"-----------------------"<<std::endl;
    printf( "Size is %dx%dx%d\n",
            poDataset->GetRasterXSize(), poDataset->GetRasterYSize(),
            poDataset->GetRasterCount() );
//    std::cout<<"-----------------------"<<std::endl;
//    if( poDataset->GetProjectionRef()  != NULL ){
//      printf( "Projection is `%s'\n", poDataset->GetProjectionRef() );
//      std::cout<<"-----------------------"<<std::endl;
//    }
    if( poDataset->GetGeoTransform( adfGeoTransform ) == CE_None )
    {
      printf( "Origin = (%.6f,%.6f)\n",
              adfGeoTransform[0], adfGeoTransform[3] );
      std::cout<<"-----------------------"<<std::endl;
      printf( "Pixel Size = (%.6f,%.6f)\n",
              adfGeoTransform[1], adfGeoTransform[5] );
    }
  }
}