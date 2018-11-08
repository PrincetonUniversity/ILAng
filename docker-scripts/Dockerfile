#FROM ubuntu:precise
#FROM ubuntu:trusty
#FROM ubuntu:xenial
FROM ubuntu:bionic

WORKDIR /app

COPY . /app

#CMD ["/bin/bash", "-c", "source build-precise-init.sh; /bin/bash"]
#CMD ["/bin/bash", "-c", "source build-trusty-init.sh; /bin/bash"]
#CMD ["/bin/bash", "-c", "source build-xenial-init.sh; /bin/bash"]
CMD ["/bin/bash", "-c", "source build-bionic-init.sh; /bin/bash"]

