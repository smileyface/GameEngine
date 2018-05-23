#include "stdafx.h"
#include "CppUnitTest.h"

#include <system\JobManager.h>
#include <system\ThreadManager.h>
#include <system\Statistic.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace SystemTests
{		
	char function_result;
	void a() { function_result = 'a'; };
	void b() { function_result = 'b'; };
	void c() { function_result = 'c'; };
	TEST_CLASS(JobManagerTest)
	{
	public:

		TEST_METHOD(handle_job_without_priorities)
		{
			//Test the adding of jobs to the job queue without the level parameter.
			JobManager::add(JobManager::make_job(SystemTests::a));
			int queue_size = JobManager::queue.size();
			Assert::AreEqual(1, queue_size, L"Queue is empty");

			//test the first jobs level
			Job job = JobManager::get_queued_job();
			bool job_level = JobPrority::MID == job.priority;
			Assert::IsTrue(job_level);

			//clean-up
			queue_size = JobManager::queue.size();
			Assert::AreEqual(0, queue_size, L"Queue is not empty");
		}

		TEST_METHOD(add_job_with_priorities)
		{
			Job r = JobManager::make_job(SystemTests::a, JobPrority::HIGH);
			JobManager::add(r);
			int queue_size = JobManager::queue.size();
			Assert::AreEqual(1, queue_size, L"Queue is empty");

			//test the first jobs level
			Job job = JobManager::get_queued_job();
			bool job_level = JobPrority::HIGH == job.priority;
			Assert::IsTrue(job_level);

			//clean-up
			queue_size = JobManager::queue.size();
			Assert::AreEqual(0, queue_size, L"Queue is not empty");
		}

		TEST_METHOD(handle_background_functions)
		{
			//test the addition manually setting priority
			JobManager::add(JobManager::make_job(SystemTests::a, JobPrority::BKGROUND, 12));
			int queue_size = JobManager::queue.size();
			Assert::AreEqual(1, queue_size, L"Queue is empty");

			//test pop job
			Job job = JobManager::get_queued_job();
			bool job_level = JobPrority::BKGROUND == job.priority;
			Assert::IsTrue(job_level);

			queue_size = 0;

			//test it is expected function
			job.function();
			Assert::AreEqual('a', function_result);
			queue_size = JobManager::queue.size();
			Assert::AreEqual(1, queue_size, L"Queue is empty");

		}

		TEST_METHOD(remove_job_by_id)
		{
			JobManager::add(JobManager::make_job(SystemTests::b, JobPrority::MID, 12));
			JobManager::add(JobManager::make_job(SystemTests::c, JobPrority::BKGROUND, 13));
			JobManager::add(JobManager::make_job(SystemTests::a, JobPrority::HIGH, 14));
			JobManager::add(JobManager::make_job(SystemTests::c, JobPrority::BKGROUND, 15));

			JobManager::remove(13);

			int queue_size = JobManager::queue.size();
			Assert::AreEqual(3, queue_size, L"Queue is empty");

			Job job = JobManager::get_queued_job();
			//test it is expected function
			job.function();
			Assert::AreEqual('a', function_result, L"Unexpected function");

			job = JobManager::get_queued_job();
			//test it is expected function
			job.function();
			Assert::AreEqual('b', function_result, L"Unexpected function");

			job = JobManager::get_queued_job();
			//test it is expected function
			job.function();
			Assert::AreEqual('c', function_result, L"Unexpected function");
		}

		TEST_METHOD(add_two_jobs_different_priorities)
		{
			JobManager::add(JobManager::make_job(SystemTests::b, JobPrority::MID, 12));
			JobManager::add(JobManager::make_job(SystemTests::a, JobPrority::HIGH, 14));

			Job job = JobManager::get_queued_job();
			//test it is expected function
			job.function();
			Assert::AreEqual('a', function_result, L"Unexpected function");

			job = JobManager::get_queued_job();
			//test it is expected function
			job.function();
			Assert::AreEqual('b', function_result, L"Unexpected function");
		}

		TEST_METHOD(add_two_jobs_same_priorities)
		{
			JobManager::add(JobManager::make_job(SystemTests::b, JobPrority::MID, 12));
			JobManager::add(JobManager::make_job(SystemTests::a, JobPrority::MID, 14));

			Job job = JobManager::get_queued_job();
			//test it is expected function
			job.function();
			Assert::AreEqual('b', function_result, L"Unexpected function");

			job = JobManager::get_queued_job();
			//test it is expected function
			job.function();
			Assert::AreEqual('a', function_result, L"Unexpected function");
		}

		TEST_METHOD(add_lambda)
		{
			Job job = JobManager::make_job([]() {
				function_result = 'd';
			});
			JobManager::add(job);

			job = JobManager::get_queued_job();
			//test it is expected function
			job.function();
			Assert::AreEqual('d', function_result, L"Unexpected function");
		}

		TEST_METHOD(run_job)
		{
			Job job = JobManager::make_job(SystemTests::a);
			//test it is expected function
			job.function();
			Assert::AreEqual('a', function_result);
		}

	};

	TEST_CLASS(ThreadManagerTest)
	{
	public:
		TEST_METHOD(function_run_test)
		{

		}

	};
}