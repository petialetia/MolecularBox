sudo apt-get update
sudo apt-get install -y build-essential 
sudo DEBIAN_FRONTEND=noninteractive apt-get install -y cmake 
sudo apt-get install -y libsdl2-dev

sudo apt-get install -y libgtest-dev
cd /usr/src/gtest
sudo cmake .
sudo make