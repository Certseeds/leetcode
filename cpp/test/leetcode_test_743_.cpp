/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-04-11 22:51:17
 * @LastEditors: nanoseeds
 */
/*  leetcode
    Copyright (C) 2020-2021 nanoseeds

    leetcode is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    leetcode is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
    */
#include "catch_main.hpp"
#include "leetcode_743_.hpp"

namespace Solution743 {
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;
Solution743 sol743;
// 无负值最短路径
// Dijkstra
TEST_CASE("1 {test 743}", "{test 743}") {
    CHECK(sol743.networkDelayTime(
            {{{7, 13, 53}, {10, 5, 86}, {5, 14, 45}, {5, 10, 49}, {5, 6, 77}, {12, 9, 95}, {6, 10, 75}, {7, 4, 61}, {8, 5, 2}, {10, 1, 45}, {11, 14, 19}, {9, 15, 15}, {6, 4, 95}, {6, 1, 4}, {8, 12, 29}, {1, 9, 15}, {10, 9, 81}, {13, 5, 13}, {9, 13, 85}, {2, 8, 45}, {7, 8, 11}, {7, 3, 63}, {2, 11, 60}, {2, 5, 59}, {6, 12, 35}, {14, 11, 69}, {10, 4, 96}, {10, 8, 33}, {11, 15, 79}, {3, 14, 42}, {6, 2, 53}, {1, 11, 99}, {11, 1, 27}, {8, 13, 75}, {14, 8, 45}, {12, 6, 99}, {7, 14, 13}, {14, 13, 46}, {4, 8, 83}, {14, 15, 28}, {6, 8, 79}, {10, 6, 2}, {2, 1, 85}, {14, 12, 37}, {5, 2, 22}, {9, 10, 97}, {4, 5, 93}, {6, 7, 3}, {13, 3, 19}, {12, 1, 34}, {7, 15, 37}, {12, 14, 66}, {4, 9, 6}, {3, 9, 45}, {15, 6, 39}, {8, 3, 92}, {12, 7, 29}, {9, 6, 24}, {15, 5, 71}, {2, 13, 99}, {9, 1, 58}, {9, 3, 61}, {3, 2, 83}, {2, 15, 52}, {8, 6, 14}, {3, 13, 62}, {3, 10, 86}, {4, 7, 58}, {8, 7, 40}, {14, 7, 67}, {15, 9, 40}, {7, 6, 6}, {14, 5, 22}, {11, 6, 20}, {4, 12, 29}, {7, 12, 18}, {1, 2, 16}, {7, 11, 20}, {1, 5, 64}, {1, 7, 27}, {1, 10, 88}, {1, 14, 48}, {15, 3, 94}, {3, 7, 21}, {5, 15, 43}, {5, 13, 23}, {15, 10, 54}, {1, 8, 36}, {3, 8, 95}, {2, 7, 94}, {9, 5, 42}, {4, 3, 90}, {11, 7, 74}, {11, 3, 16}, {3, 11, 10}, {8, 11, 29}, {10, 13, 79}, {9, 8, 75}, {14, 10, 13}, {3, 5, 81}, {8, 14, 45}, {13, 1, 85}, {5, 4, 78}, {11, 5, 4}, {12, 8, 43}, {2, 6, 99}, {12, 13, 72}, {10, 3, 8}, {9, 4, 62}, {7, 9, 0}, {15, 7, 50}, {12, 2, 20}, {1, 4, 0}, {10, 12, 48}, {6, 9, 22}, {11, 8, 52}, {13, 7, 29}, {4, 10, 45}, {6, 15, 6}, {9, 11, 84}, {3, 15, 85}, {15, 11, 76}, {8, 9, 72}, {8, 15, 46}, {13, 6, 32}, {2, 12, 99}, {11, 10, 15}, {2, 3, 36}, {15, 12, 46}, {12, 15, 70}, {5, 3, 21}, {14, 4, 42}, {8, 4, 64}, {1, 6, 90}, {13, 11, 73}, {15, 14, 84}, {9, 2, 98}, {7, 2, 98}, {1, 12, 28}, {4, 15, 3}, {2, 9, 70}, {4, 14, 95}, {11, 12, 80}, {14, 3, 89}, {8, 2, 49}, {4, 1, 25}, {8, 1, 68}, {5, 1, 27}, {9, 7, 97}, {13, 2, 44}, {5, 7, 71}, {10, 11, 89}, {3, 12, 67}, {14, 1, 77}, {10, 15, 92}, {2, 4, 79}, {4, 6, 25}, {5, 9, 81}, {6, 14, 97}, {11, 4, 96}, {9, 12, 43}, {13, 10, 7}, {10, 7, 19}, {15, 13, 76}, {7, 5, 16}, {13, 14, 45}, {12, 3, 59}, {13, 9, 60}, {6, 13, 62}, {13, 4, 42}, {5, 12, 3}, {4, 11, 79}, {7, 1, 58}, {14, 6, 64}, {12, 11, 5}, {2, 10, 92}, {10, 2, 45}, {7, 10, 90}, {13, 15, 56}, {1, 3, 0}, {4, 2, 53}, {5, 11, 25}, {15, 4, 39}, {12, 5, 34}, {6, 5, 70}, {1, 15, 23}, {15, 8, 40}, {5, 8, 11}, {2, 14, 57}, {4, 13, 19}, {15, 1, 18}, {12, 4, 95}, {1, 13, 22}, {11, 9, 74}, {14, 9, 86}, {11, 13, 46}, {8, 10, 10}, {14, 2, 43}, {3, 4, 91}, {15, 2, 66}, {10, 14, 32}, {13, 8, 67}, {6, 3, 2}, {9, 14, 3}, {6, 11, 71}, {11, 2, 67}, {3, 1, 65}, {13, 12, 0}, {3, 6, 27}, {12, 10, 77}}},
            15, 2) == 70);
    CHECK(sol743.networkDelayTime({{{2, 1, 1}, {2, 3, 1}, {3, 4, 1}}}, 4, 2) == 2);
    CHECK(sol743.networkDelayTime({{{1, 2, 1}}}, 2, 1) == 1);
    CHECK(sol743.networkDelayTime({{{1, 2, 1}}}, 2, 2) == -1);
    CHECK(sol743.networkDelayTime(
            {{{10, 9, 79}, {15, 10, 58}, {14, 4, 99}, {14, 12, 29}, {12, 15, 26}, {1, 15, 78}, {2, 11, 88}, {7, 3, 4}, {3, 1, 52}, {11, 3, 91}, {11, 12, 11}, {5, 10, 81}, {1, 7, 44}, {12, 13, 52}, {3, 14, 83}, {10, 4, 26}, {5, 9, 72}, {5, 14, 32}, {13, 10, 32}, {15, 6, 2}, {3, 9, 18}, {1, 11, 45}, {5, 8, 98}, {7, 13, 33}, {1, 2, 59}, {4, 11, 79}, {11, 1, 12}, {8, 5, 79}, {2, 14, 93}, {3, 6, 53}, {11, 10, 40}, {14, 2, 33}, {4, 9, 61}, {3, 8, 10}, {10, 7, 1}, {8, 3, 58}, {1, 12, 20}, {5, 1, 51}, {7, 1, 37}, {9, 7, 34}, {9, 10, 48}, {8, 4, 90}, {12, 1, 92}, {6, 4, 99}, {2, 15, 3}, {2, 3, 80}, {2, 4, 60}, {15, 14, 75}, {2, 7, 20}, {15, 8, 20}, {5, 12, 19}, {13, 3, 74}, {7, 5, 6}, {9, 6, 73}, {9, 14, 49}, {15, 1, 56}, {8, 2, 10}, {7, 9, 9}, {12, 5, 67}, {6, 3, 29}, {9, 4, 38}, {6, 9, 42}, {5, 3, 57}, {3, 2, 48}, {12, 6, 77}, {10, 15, 15}, {12, 4, 68}, {14, 1, 52}, {13, 4, 80}, {4, 1, 84}, {14, 10, 68}, {2, 12, 81}, {2, 1, 31}, {6, 14, 52}, {7, 8, 68}, {4, 12, 73}, {8, 14, 88}, {13, 5, 92}, {6, 1, 3}, {9, 11, 80}, {3, 15, 23}, {15, 4, 84}, {5, 11, 41}, {7, 11, 42}, {11, 7, 86}, {9, 15, 63}, {1, 4, 36}, {3, 13, 82}, {6, 15, 91}, {13, 6, 64}, {14, 11, 32}, {11, 5, 68}, {6, 5, 55}, {4, 5, 35}, {13, 1, 1}, {4, 10, 47}, {12, 9, 1}, {7, 10, 44}, {3, 7, 23}, {8, 12, 68}, {8, 6, 13}, {2, 9, 19}, {10, 6, 91}, {7, 12, 80}, {8, 7, 12}, {4, 7, 4}, {9, 2, 67}, {14, 9, 29}, {15, 13, 80}, {6, 8, 62}, {15, 12, 36}, {1, 3, 48}, {2, 10, 67}, {9, 13, 55}, {11, 6, 62}, {8, 11, 92}, {13, 15, 30}, {4, 13, 97}, {5, 4, 25}, {4, 2, 9}, {15, 5, 5}, {15, 2, 45}, {10, 8, 23}, {14, 5, 43}, {5, 13, 98}, {14, 13, 73}, {4, 8, 29}, {10, 5, 0}, {11, 13, 68}, {9, 12, 91}, {12, 2, 56}, {9, 1, 23}, {14, 6, 80}, {9, 5, 10}, {12, 11, 89}, {5, 15, 94}, {7, 2, 20}, {3, 12, 89}, {2, 13, 9}, {11, 2, 1}, {10, 13, 85}, {6, 10, 76}, {1, 10, 2}, {14, 15, 20}, {3, 11, 15}, {11, 8, 62}, {12, 7, 63}, {8, 15, 91}, {8, 10, 30}, {12, 3, 80}, {5, 7, 94}, {13, 2, 60}, {14, 8, 77}, {10, 12, 67}, {13, 8, 9}, {13, 11, 48}, {5, 6, 77}, {10, 3, 51}, {4, 15, 84}, {13, 12, 10}, {13, 14, 28}, {4, 6, 46}, {3, 10, 53}, {14, 7, 48}, {10, 11, 21}, {15, 11, 99}, {12, 10, 93}, {11, 14, 73}, {15, 3, 81}, {2, 5, 22}, {12, 8, 20}, {6, 13, 24}, {8, 13, 41}, {8, 9, 98}, {2, 6, 98}, {7, 15, 27}, {6, 11, 15}, {7, 14, 72}, {10, 14, 96}, {1, 8, 18}, {1, 6, 2}, {3, 4, 78}, {4, 3, 10}, {11, 4, 54}, {12, 14, 40}, {3, 5, 63}, {10, 2, 94}, {1, 9, 57}, {6, 12, 12}, {9, 8, 37}, {8, 1, 77}, {13, 7, 80}, {10, 1, 25}, {9, 3, 37}, {4, 14, 28}, {1, 13, 88}, {1, 5, 45}, {7, 4, 65}, {6, 2, 19}, {11, 15, 37}, {7, 6, 90}, {2, 8, 1}, {1, 14, 63}, {5, 2, 47}, {15, 9, 34}, {11, 9, 41}, {15, 7, 90}, {13, 9, 45}, {14, 3, 34}, {6, 7, 44}}},
            15, 9) == 49);
    CHECK(true);
    CHECK_FALSE(false);
}
}
