#include "../Tests.h"

#include <Library.h>
#include <Core/Loadable.h>	//TODO

using namespace t3d::core;

#define CLASS Test_Loadable

TEST_CLASS
{
protected:
	class TestLoadable : public Loadable
	{
	public:
		void init()
		{
			Loadable::Begin b(this);
		}


		void refresh()
		{
			Loadable::Begin b(this);
		}
	};


	template <typename T>
	void assertSimpleRun(T &mf)
	{
		TestLoadable testLoadable;
		bool notifiedForStart = false;
		bool notifiedForFinish = false;
		bool error = false;

        testLoadable.pIsLoading.addOnChangedListener([&]()
		{
			if (testLoadable.pIsLoading)
			{
				if (notifiedForFinish)
					error = true;

				notifiedForStart = true;
			}
			else
			{
				if (!notifiedForStart)
					error = true;

				notifiedForFinish = true;
			}
		});

		mf(testLoadable);

		EXPECT_FALSE(error);
		EXPECT_TRUE(notifiedForStart);
		EXPECT_TRUE(notifiedForFinish);
	}
};


TEST_CASE(simpleInit)
{
	auto f = std::mem_fn(&TestLoadable::init);
	assertSimpleRun(f);
}


TEST_CASE(simpleReinit)
{
	auto f = std::mem_fn(&TestLoadable::refresh);
	assertSimpleRun(f);
}
