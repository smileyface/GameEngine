#include "stdafx.h"
#include "CppUnitTest.h"

#include <system\JobManager.h>
#include <system\Statistic.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace SystemTests
{		
	void a() {};
	TEST_CLASS(JobManagerTest)
	{
	public:


		TEST_METHOD(handle_job_without_priorities)
		{
			//Test the adding of jobs to the job queue without the level parameter.
			JobManager::add(SystemTests::a);
			int queue_size = JobManager::queue.size();
			Assert::AreEqual(1, queue_size);

			//test the first jobs level
			Job job = JobManager::get_queued_job();
			bool job_level = JobPrority::MID == job.first;
			Assert::IsTrue(job_level);

			//clean-up
			queue_size = JobManager::queue.size();
			Assert::AreEqual(0, queue_size);
		}

		TEST_METHOD(add_job_with_priorities)
		{
			//JobManager::add(SystemTests::a, JobManager::HIGH);
			//int queue_size = JobManager::queue/
			Assert::Fail(L"Unimplemented");
		}

		TEST_METHOD(add_two_jobs_different_priorities)
		{
			Assert::Fail(L"Unimplemented");
		}

		TEST_METHOD(add_two_jobs_same_priorities)
		{
			Assert::Fail(L"Unimplemented");
		}

		TEST_METHOD(add_lambda)
		{
			
			Assert::Fail(L"Unimplemented");
		}

		//TODO: Handle interupts
		TEST_METHOD(run_job)
		{
			Assert::Fail(L"Unimplemented");
		}


	};
}