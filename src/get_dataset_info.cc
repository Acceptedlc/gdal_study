
#include <iostream>
#include <gdal_priv.h>
#include <cpl_conv.h>

int main() {

  GDALDataset *poDataset;
  GDALAllRegister();
  poDataset = (GDALDataset *) GDALOpen(
          " ",
          GA_ReadOnly);
  printf( "Projection is `%s'\n", poDataset->GetProjectionRef() );
  double adfGeoTransform[6];
  poDataset->GetGeoTransform(adfGeoTransform);
  for(int i = 0; i< 6;i ++) {
    std::cout << adfGeoTransform[i] << std::endl;
  }

//  if (poDataset == NULL) {
//    std::cout<< "fail" << std::endl;
//  } else {
//    double adfGeoTransform[6];
//
////    printf( "Driver: %s/%s\n",
////            poDataset->GetDriver()->GetDescription(),
////            poDataset->GetDriver()->GetMetadataItem( GDAL_DMD_LONGNAME ) );
////    std::cout<<"-----------------------"<<std::endl;
//    printf( "Size is %dx%dx%d\n",
//            poDataset->GetRasterXSize(), poDataset->GetRasterYSize(),
//            poDataset->GetRasterCount() );
////    std::cout<<"-----------------------"<<std::endl;
////    if( poDataset->GetProjectionRef()  != NULL ){
////      printf( "Projection is `%s'\n", poDataset->GetProjectionRef() );
////      std::cout<<"-----------------------"<<std::endl;
////    }
//    if( poDataset->GetGeoTransform( adfGeoTransform ) == CE_None )
//    {
//      printf( "Origin = (%.6f,%.6f)\n",
//              adfGeoTransform[0], adfGeoTransform[3] );
//      std::cout<<"-----------------------"<<std::endl;
//      printf( "Pixel Size = (%.6f,%.6f)\n",
//              adfGeoTransform[1], adfGeoTransform[5] );
//    }
//  }
}