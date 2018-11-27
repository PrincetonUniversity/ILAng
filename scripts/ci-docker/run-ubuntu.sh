# bionic
docker image build -f Dockerfile-bionic -t vm/ci:bionic .
docker run --name bionic-build vm/ci:bionic 

# xenial
docker image build -f Dockerfile-xenial -t vm/ci:xenial
docker run --name xenial-build vm/ci:xenial 

