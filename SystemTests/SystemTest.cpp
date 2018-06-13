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

	/**
		@class JobManagerTest
		@brief Test the JobManager

	*/

	TEST_CLASS(JobManagerTest)
	{
	public:

		JobManager job_manager;
		/**
		@test This test case handles a job without priorities
	*/

		TEST_METHOD(add_job_without_priorities)
		{
			//Test the adding of jobs to the job queue without the level parameter.
			job_manager.add(job_manager.make_job(SystemTests::a));
			Assert::AreEqual(1, job_manager.queue_size(), L"Queue is empty");

			//test the first jobs level
			Job job = job_manager.get_queued_job();
			bool job_level = JobPrority::MID == job.priority;
			Assert::IsTrue(job_level);

			//clean-up
			Assert::AreEqual(0, job_manager.queue_size(), L"Queue is not empty");
		}

		/**
		@test This test case handles a job with priorities
		*/
		TEST_METHOD(add_job_with_priorities)
		{
			Job r = job_manager.make_job(SystemTests::a, JobPrority::HIGH);
			job_manager.add(r);
			Assert::AreEqual(1, job_manager.queue_size(), L"Queue is empty");

			//test the first jobs level
			Job job = job_manager.get_queued_job();
			bool job_level = JobPrority::HIGH == job.priority;
			Assert::IsTrue(job_level);

			//clean-up
			Assert::AreEqual(0, job_manager.queue_size(), L"Queue is not empty");
		}

		/**
		@test This test case handles a job with priorities
		*/
		TEST_METHOD(handle_persistant_functions)
		{
			//test the addition manually setting priority
			job_manager.add(job_manager.make_job(SystemTests::a, JobPrority::PERSISTANT, 12));
			Assert::AreEqual(1, job_manager.queue_size(), L"Queue is empty");

			//test pop job
			Job job = job_manager.get_queued_job();
			bool job_level = JobPrority::PERSISTANT == job.priority;
			Assert::IsTrue(job_level);

			//test it is expected function
			job.function();
			Assert::AreEqual('a', function_result);
			Assert::AreEqual(1, job_manager.queue_size(), L"Queue is empty");

		}

		/**
		@test This test case removes jobs by ID and also tests persistants staying power
		*/
		TEST_METHOD(remove_job_by_id)
		{
			job_manager.add(job_manager.make_job(SystemTests::b, JobPrority::MID, 12));
			job_manager.add(job_manager.make_job(SystemTests::c, JobPrority::PERSISTANT, 13));
			job_manager.add(job_manager.make_job(SystemTests::a, JobPrority::HIGH, 14));
			job_manager.add(job_manager.make_job(SystemTests::c, JobPrority::PERSISTANT, 15));

			job_manager.remove(13);

			int queue_size = job_manager.queue_size();
			Assert::AreEqual(3, queue_size, L"Queue is empty");

			Job job = job_manager.get_queued_job();
			//test it is expected function
			Assert::AreEqual(14, job.job_id, L"Unexpected function");

			job = job_manager.get_queued_job();
			//test it is expected function
			Assert::AreEqual(15, job.job_id, L"Unexpected function");

			job = job_manager.get_queued_job();
			//test it is expected function
			Assert::AreEqual(15, job.job_id, L"Unexpected function");

			job_manager.remove(15);

			job = job_manager.get_queued_job();
			//test it is expected function
			Assert::AreEqual(12, job.job_id, L"Unexpected function");

			Assert::AreEqual(0, job_manager.queue_size(), L"Queue is not empty");

		}

		TEST_METHOD(add_two_jobs_different_priorities)
		{
			job_manager.add(job_manager.make_job(SystemTests::b, JobPrority::MID, 12));
			job_manager.add(job_manager.make_job(SystemTests::a, JobPrority::HIGH, 14));

			Job job = job_manager.get_queued_job();
			//test it is expected function
			job.function();
			Assert::AreEqual('a', function_result, L"Unexpected function");

			job = job_manager.get_queued_job();
			//test it is expected function
			job.function();
			Assert::AreEqual('b', function_result, L"Unexpected function");
		}

		TEST_METHOD(add_two_jobs_same_priorities)
		{
			job_manager.add(job_manager.make_job(SystemTests::b, JobPrority::MID, 12));
			job_manager.add(job_manager.make_job(SystemTests::a, JobPrority::MID, 14));

			Job job = job_manager.get_queued_job();
			//test it is expected function
			job.function();
			Assert::AreEqual('b', function_result, L"Unexpected function");

			job = job_manager.get_queued_job();
			//test it is expected function
			job.function();
			Assert::AreEqual('a', function_result, L"Unexpected function");
		}

		TEST_METHOD(add_lambda)
		{
			Job job = job_manager.make_job([]() {
				function_result = 'd';
			});
			job_manager.add(job);

			job = job_manager.get_queued_job();
			//test it is expected function
			job.function();
			Assert::AreEqual('d', function_result, L"Unexpected function");
		}

		TEST_METHOD(run_job)
		{
			Job job = job_manager.make_job(SystemTests::a);
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