#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>
#include <string>
#include "../app_config.h"


TEST_CASE( "Test functions for get in config define info.", "[get-functions]" ){
	SECTION("get connect string")
	{
		CHECK(app_config::get_connect("config.txt") == "host=hostname "
																									 "port=5432 "
																									 "dbname=dbname "
																									 "user=username "
																									 "password=secret"
					);
	}
}

int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}
