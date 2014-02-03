#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;

const auto PAYLOAD_SIZE = 100000000;
const auto NUM_SAMPLES = 10;
const auto MAX_CORES = 16;
// Epsilon is the 'threshold ratio' of more-threads-than-cores situation
// I figured it out experimentally; should work for sure for <=4 cores, and probably more
const auto EPSILON = 0.3;

// Something for the processor to do
// It's important that the operation is CPU-bound; I tried to multiply by rand()
// and discovered that it's IO-bound
void payload(int count) {
    double mul=1;
    for(auto i=0; i<count; ++i) {
        mul = mul*i;
    }
}

// Same payload, but numThreads times
void parallelPayload(int numThreads) {
    std::thread threads[MAX_CORES];
    for (auto i=0;i<numThreads;++i) {
        threads[i] = thread(payload, PAYLOAD_SIZE);
    }
    
    for (auto i=0;i<numThreads;++i) {
        threads[i].join();
    }
}

// Run parallel payload several times and benchmark it
double benchmarkPayload(int numThreads) {
    double avg = 0;
    for (auto sample=0; sample < NUM_SAMPLES; ++sample) {
        time_point<system_clock> start, end;
        start = system_clock::now();
        
        parallelPayload(numThreads);
    
        end = system_clock::now();
        duration<double> elapsed_seconds = end-start;
        avg += elapsed_seconds.count();
    }
    return avg / NUM_SAMPLES;
}


int main(int argc, const char * argv[])
{
    double firstTime = benchmarkPayload(1);
    
    for (auto num_cores=2;num_cores<MAX_CORES;++num_cores) {
        double time = benchmarkPayload(num_cores);
        if (abs(time-firstTime)/firstTime > EPSILON) {
            cout << "Number of cores = " << num_cores-1 << endl;
            return 0;
        }
    }
    cout << "Number of cores is larger than " << MAX_CORES << endl;
    return 0;
}

