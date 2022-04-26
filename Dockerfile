# docker build -t clangdev:latest .

FROM continuumio/miniconda3

# install basic tools
RUN apt update && apt install vim -y

# use conda-forge
RUN conda config --add channels conda-forge
RUN conda config --set channel_priority strict

# create new env
RUN conda create -n py38 python=3.8 -y

# make RUN commands use the new environment:
SHELL ["conda", "run", "-n", "py38", "/bin/bash", "-c"]

# install tools
RUN conda install clangdev gxx libcxx cmake ninja -y

# insyall libs
RUN conda install glog boost protobuf -y

# set env
# TODO use ${CONDA_PREFIX}
ENV LD_LIBRARY_PATH="/opt/conda/envs/py38/lib:${LD_LIBRARY_PATH}"
ENV LIBRARY_PATH="/opt/conda/envs/py38/lib:${LIBRARY_PATH}"
RUN echo "conda activate py38" >> ~/.bashrc
