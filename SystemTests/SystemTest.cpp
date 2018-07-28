#include "stdafx.h"
#include "CppUnitTest.h"

#include <iostream>

#include <JobManager\JobManager.h>
#include <JobManager/Job.h>
#include <ThreadManager\ThreadManager.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace SystemTests
{		
	char function_result;
	void a() { function_result = 'a'; };
	void b() { function_result = 'b'; };
	void c() { function_result = 'c'; };
	void d() { function_result = 'd'; };

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
			job_manager.add(Job(SystemTests::a));
			Assert::AreEqual(1, job_manager.queue_size(), L"Queue is empty");

			//test the first jobs level
			Job job = job_manager.get_next_job();
			bool job_level = JobPriority::MID == job.get_priority();
			Assert::IsTrue(job_level);

			//clean-up
			Assert::AreEqual(0, job_manager.queue_size(), L"Queue is not empty");
		}

		/**
		@test This test case handles a job with priorities
		*/
		TEST_METHOD(add_job_with_priorities)
		{
			Job r(SystemTests::a);
			r.set_priority(JobPriority::HIGH);
			job_manager.add(r);
			Assert::AreEqual(1, job_manager.queue_size(), L"Queue is empty");

			//test the first jobs level
			Job job = job_manager.get_next_job();
			bool job_level = JobPriority::HIGH == job.get_priority();
			Assert::IsTrue(job_level);

			//clean-up
			Assert::AreEqual(0, job_manager.queue_size(), L"Queue is not empty");
		}

		/**
		@test This test case handles a job with priorities
		*/
		TEST_METHOD(handle_persistant_functions)
		{
			Job test_job(SystemTests::a);
			test_job.set_priority(JobPriority::PERSISTANT);
			idType test_job_id = test_job.get_job_id();

			//test the addition manually setting priority
			job_manager.add(test_job);
			Assert::AreEqual(1, job_manager.queue_size(), L"Queue is empty");

			//test pop job
			Job job = job_manager.get_next_job();
			bool job_level = JobPriority::PERSISTANT == job.get_priority();
			Assert::IsTrue(job_level);

			//test it is expected function
			job.execute();
			Assert::AreEqual('a', function_result);
			Assert::AreEqual(1, job_manager.queue_size(), L"Queue is empty");

		}

		/**
		@test This test case removes jobs by ID and also tests persistants staying power
		*/
		TEST_METHOD(remove_job_by_id)
		{
			Job test_job_1(SystemTests::b);
			test_job_1.set_priority(JobPriority::MID);

			Job test_job_2(SystemTests::c);
			test_job_2.set_priority(JobPriority::PERSISTANT);

			Job test_job_3(SystemTests::a);
			test_job_3.set_priority(JobPriority::HIGH);

			Job test_job_4(SystemTests::d);
			test_job_4.set_priority(JobPriority::PERSISTANT);

			job_manager.add(test_job_1);
			job_manager.add(test_job_2);
			job_manager.add(test_job_3);
			job_manager.add(test_job_4);

			//todo Finish this test case

			job_manager.remove(test_job_3);

			Job cur_job = job_manager.get_next_job();
			bool is_job = (cur_job == test_job_2) || (cur_job == test_job_4);
			Assert::IsTrue(is_job, L"Job 2 or Job 4 is not expected job");

			cur_job = job_manager.get_next_job();
			is_job = (cur_job == test_job_2) || (cur_job == test_job_4);
			Assert::IsTrue(is_job, L"Job 2 or Job 4 is not expected job");

			cur_job = job_manager.get_next_job();
			is_job = cur_job == test_job_1;
			Assert::IsTrue(is_job, L"Job 1 is not expected job");



			//next frame
			cur_job = job_manager.get_next_job();
			is_job = (cur_job == test_job_2) || (cur_job == test_job_4);
			Assert::IsTrue(is_job, L"Job 2 or Job 4 is not expected job");

			cur_job = job_manager.get_next_job();
			is_job = (cur_job == test_job_2) || (cur_job == test_job_4);
			Assert::IsTrue(is_job, L"Job 2 or Job 4 is not expected job");

		}

		TEST_METHOD(add_two_jobs_different_priorities)
		{
			Job test_job_1(SystemTests::b);

			Job test_job_2(SystemTests::a);
			test_job_2.set_priority(JobPriority::HIGH);

			job_manager.add(test_job_1);
			job_manager.add(test_job_2);

			Job job = job_manager.get_next_job();
			//test it is expected function
			job.execute();
			Assert::AreEqual('a', function_result, L"Unexpected function");

			job = job_manager.get_next_job();
			//test it is expected function
			job.execute();
			Assert::AreEqual('b', function_result, L"Unexpected function");
		}

		TEST_METHOD(add_two_jobs_same_priorities)
		{
			Job test_job_1(SystemTests::b);

			Job test_job_2(SystemTests::a);

			job_manager.add(test_job_1);
			job_manager.add(test_job_2);

			Job job = job_manager.get_next_job();
			//test it is expected function
			job.execute();
			Assert::AreEqual('b', function_result, L"Unexpected function");

			job = job_manager.get_next_job();
			//test it is expected function
			job.execute();
			Assert::AreEqual('a', function_result, L"Unexpected function");
		}

		TEST_METHOD(add_lambda)
		{
			Job job([]() {
				function_result = 'd';
			});
			job_manager.add(job);

			job = job_manager.get_next_job();
			//test it is expected function
			job.execute();
			Assert::AreEqual('d', function_result, L"Unexpected function");

			char z = 'z';
			Job job_2([&]() {
				function_result = z;
			});
			job_manager.add(job_2);

			job = job_manager.get_next_job();
			//test it is expected function
			job.execute();
			Assert::AreEqual('z', function_result, L"Unexpected function");

			z = 'q';
			auto r = [&]() {
				function_result = z;
			};
			job_manager.add(Job(r));

			job = job_manager.get_next_job();
			//test it is expected function
			job.execute();
			Assert::AreEqual('q', function_result, L"Unexpected function");
		}

		TEST_METHOD(run_job)
		{
			Job job(SystemTests::a);
			//test it is expected function
			job.execute();
			Assert::AreEqual('a', function_result);
		}

	};
}