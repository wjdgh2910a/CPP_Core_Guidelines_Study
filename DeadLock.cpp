#include<iostream>
#include<chrono>
#include<mutex>
#include<thread>

void deadLock(std::mutex& mut1, std::mutex& mut2)
{
	std::lock_guard<std::mutex> guard1(mut1);

	std::cout << "Thread ID : " << std::this_thread::get_id() << std::endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(1));

	std::lock_guard<std::mutex> guard2(mut2);

	std::cout << "Thread ID : " << std::this_thread::get_id() << std::endl;
}
void UniqueLock(std::mutex& mut1, std::mutex& mut2)
{
	std::unique_lock<std::mutex> guard1(mut1,std::defer_lock);

	std::unique_lock<std::mutex> guard2(mut2, std::defer_lock);
	std::lock(guard1, guard2);

	std::cout << "Thread ID : " << std::this_thread::get_id() << std::endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(1));

	std::cout << "Thread ID : " << std::this_thread::get_id() << std::endl;
}
void ScopedLock(std::mutex& mut1, std::mutex& mut2)
{
	std::scoped_lock ScopedLock(mut1, mut2);

	std::cout << "Thread ID : " << std::this_thread::get_id() << std::endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(1));

	std::cout << "Thread ID : " << std::this_thread::get_id() << std::endl;
}

void main()
{
	std::mutex mut1, mut2;

	//std::thread t1([&] {deadLock(mut1, mut2); });
	//std::thread t2([&] {deadLock(mut2, mut1); });
	//std::thread t1([&] {deadLock(mut1, mut2); });
	//std::thread t2([&] {deadLock(mut1, mut2); });
	//std::thread t1([&] {UniqueLock(mut1, mut2); });
	//std::thread t2([&] {UniqueLock(mut2, mut1); });
	std::thread t1([&] {ScopedLock(mut1, mut2); });
	std::thread t2([&] {ScopedLock(mut2, mut1); });
	t1.join();
	t2.join();

}