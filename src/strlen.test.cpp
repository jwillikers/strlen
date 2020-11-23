#include "strlen.h"
#include <boost/ut.hpp>
#include <string_view>

int main() {
    using namespace boost::ut;

    "should_return_zero_given_empty_string"_test = [] {
        constexpr std::string_view s{};
        expect(0_i == my_strlen(s.data()));
    };

    "should_return_zero_given_null_pointer"_test = [] {
        expect(0_i == my_strlen(nullptr));
    };

    "should_return_one_given_a_single_character"_test = [] {
        constexpr std::string_view s{"a"};
        expect(1_i == my_strlen(s.data()));
    };

    "should_calculate_size_given_string_of_length_two"_test = [] {
        constexpr std::string_view s{"ab"};
        expect(2_i == my_strlen(s.data()));
    };
}