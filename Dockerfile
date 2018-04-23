FROM daocloud.io/ubuntu:16.04
WORKDIR /root
RUN apt update
RUN apt install git
RUN git clone https://github.com/OSGeo/gdal.git 
