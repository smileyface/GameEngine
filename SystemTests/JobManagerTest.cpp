#include "stdafx.h"
#include "CppUnitTest.h"

#include "../GameEngine/JobManager.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace SystemTests
{		
	TEST_CLASS(JobManagerTest)
	{
	public:
		void a() { };

		TEST_METHOD(initalization)
		{

		}

		TEST_METHOD(add_job_without_level)
		{
			
			//Test the adding of jobs to the job queue without the level parameter.
			Assert::Fail(L"Hello");
		}

		TEST_METHOD(add_job)
		{

			//TODO: Without Level
			//TODO: With Level
			//TODO: With two different levels
			//TODO: With two same levels
			//TODO: Lambda
			//TODO: Handle interupts

			Assert::Fail(0);
		}

		TEST_METHOD(run_job)
		{
			Assert::Fail(0);
		}


	};
}