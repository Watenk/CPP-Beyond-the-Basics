
#include <queue>
#include <thread>
#include <iostream>
#include <mutex>

int counter = 0;
std::mutex counterMutex;
bool done = false;

std::queue<int> goods;

void producer()
{
    std::cout << "Starting producer..." << std::endl;

    for (int i = 0; i < 500; ++i)
    {
        std::lock_guard<std::mutex> lock(counterMutex);
        goods.push(i);
        counter++;
    }

    done = true;

    std::cout << "Finished producer..." << std::endl;
}

void consumer()
{
    std::cout << "Starting consumer..." << std::endl;

    while (!done)
    {
        while (!goods.empty())
        {
            std::lock_guard<std::mutex> lock(counterMutex);
            goods.pop();
            counter--;
        }
    }

    std::cout << "Finished consumer..." << std::endl;
}

int main()
{
    counter = 0;
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    std::cout << "Net: " << counter << " " << goods.size() << std::endl;

	std::cin.get();
}