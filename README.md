# C++ Core Guidelines [![xx](https://img.shields.io/badge/C++_Core_Guidelines-blue?logo=data:image/png;base64,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&labelColor=CED8F6&logoWidth=30&style=flat "C++ Core Guidelines")](https://github.com/isocpp/CppCoreGuidelines)


# C++ Core Guidelines [![xx](https://img.shields.io/badge/C++_Core_Guidelines-blue?logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABcAAAAaCAYAAABctMd+AAAFX0lEQVR42p2WCVCTVxDH3zhjW6e29piqg2c7trWlnq21to7tqAhBrNYTZfBChCREsaAIWhVRSyBBOSVyJyEHFhWp6EDtYBVBECEBggLmMPFWvKrgUf7dfNFYW2yxb2bn5Xtv3293//uSLwzAfxpfdXaYQGHSBmSehkBpzhepbCO7cu7foWpb/6BcazxfbmwTKs1YtksP+8zPaXkQlHsuZaX64qAXhi/M+vVlfq5lhUBpMYs057E8w4BlMh0Hp5l7pnV7FVaB6tz3GwvO9+gSPEht9QhSWcpEahsCs5sJyEE585Nx85MgtN/EBRGqrRUijc3rufAAuXG4XVeBwgihwuSELEypxbyEU/BOqIFPUi3m02x/9qX1Jz50juQyUSXGfH52y2gnXBTf9JJQZY0khxsilRX+afVctkt26uBNkBCFATm/2VBquI7Klps4QrOcnkOUjdz+YvLzJ3/7Oft54twK1l7Y2tHR8QrjK4wJq/KvISCzkSvVnzLxTa7F0lQd9lZewp22h+hs/N7+CPurL5NUnL9TKpG8GSF7ruPrqGPpzD+jgaLW/VUGetZDZ7mFrgyD7Q4C0usoSB1EOY2YKS3HwEAtunlnglE5TvBSirwgqQbHm1o7BT36o6PTdePVdvgkVsN1VQG6zd0FNmsnmHcGGEGdcO/EU9hx0PSPw3XW25AWXkGExoy4orPPVHW3/SESC3R42zcLbEYK2Lw0Aqc7zN48v9TTWJxiougtaLQ+Cz6s76BbUgWBNhSLZKWYJTWRxg04euYGDp00Y8yq3WCTthOYsl1A2c6mzGemgs0nuJ/MAH52CYS5WVi9WwX9pWI0t5ag+UYJ6q8UIzQvD4GKVMRWDkJ0uSvC9kkwPbYaLn4HqHyCuMVjMF+Fvn5ysKlJ6L1EjiEClSPYkhQLwvavQVxNT8RW9cPW4y6IKnPYZrLoEy6QVA2AuOJ9xFQOxI6aPggv/gxDQ0PApqXhE5EWest1FFaaMSIwF3vKjWg414oPA1WP4YWrsb22B0H6ErQPIo/15mwTWdypfkjUD+Lg0pPvIbneBZtKh2H0hlAwr3QMD96Npgs3UVJrxadBGhRVWdBy8RY+EmrssjRCIC/CCk0ywvIzUH1hHxquFcBAprtcgAXx0RgV7AtJ9buIoQDuUXPRffJWkiONZJGBTYnH0JVaDFyuBOMlor+/Eq4r88Cm73za0EXJ1NCEsxQVzwypogFs7Gp8EzkRvbyCwYZuBhu5FnHqo9hbYYKrUO1oKDWRGuoI+B3XUOdV5L5Ii2UNSCw24+9j35EGTAlQYsjsFPBWZCDvsN6513q7HT/mVaOnHTyPu4JPzQ4VZJE02acxef1B9PEQY29pPTob9+53/lNwos6M19y2gH0bTxlnPjYKJsg5gzmSMgz2IY0mrCcJ1qIvbxvKdGZ0ZZw02DBgWjTYV+tInkjSnT7PJpaPHOyLNT+nd5+WQOANjk23KHJcjzfdNiNBW4a7bQ86hbZRFak/VeAdd8r4y3WOc5MjyagnXlTBjCQ1Y+yNV5mbOI55iO8xTwltkhOBuWCfh2PEwkSEpxZD84seh8qboCW9I2QlGL0oiaoM5/zI3wHlxYJ5RN9nPEkSG+X/+tO3xpTocYwXU0gboECcMxlXBRuzlkqMABv/g2MeE0bZ0vokLlPO33EutohNFY9/7muOecbOoQxqmGcc3eFtziAcaGKkE0jm2Cc/8q9jPOn8Lr2g2YSNvZiHJIJ5xFxinlIqe4sTSObQl9Yp06sE3sgmbXvrhf9aMHfxB3Q4k7lHgwI5GkYzrdvBSlr/+P/+b3EaNWksQQ8QkCQQF1Pjx3Xl3J9SIE6SL7uR/QAAAABJRU5ErkJggg==&labelColor=CED8F6&logoWidth=30&style=flat "C++ Core Guidelines")](https://github.com/isocpp/CppCoreGuidelines)

Delegate
========

[![Codacy Badge](https://app.codacy.com/project/badge/Grade/fd38b54e4dfa4fa8acd13cc9b591b039)](https://www.codacy.com/gh/SharpSnake/TestDelegate/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=SharpSnake/TestDelegate&amp;utm_campaign=Badge_Grade)
[![Build status](https://ci.appveyor.com/api/projects/status/f2on7ikl00nrs8xk?svg=true)](https://ci.appveyor.com/project/SharpSnake/testdelegate)
[![CircleCI](https://dl.circleci.com/status-badge/img/gh/SharpSnake/TestDelegate/tree/master.svg?style=svg)](https://dl.circleci.com/status-badge/redirect/gh/SharpSnake/TestDelegate/tree/master)
![GitHub top language](https://img.shields.io/github/languages/top/SharpSnake/Delegate)
[![C++ Version](https://img.shields.io/badge/%2Fstd-%3E%3D%20C%2B%2B11-blue)](https://github.com/AnthonyCalandra/modern-cpp-features#c11-language-features)
![Platform](https://img.shields.io/badge/platform-windows%20%7C%20macos%20%7C%20linux-orange)
![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/SharpSnake/Delegate)
![GitHub last commit](https://img.shields.io/github/last-commit/SharpSnake/Delegate?color=%23FF69B4)
[![MIT licensed](https://img.shields.io/badge/license-MIT-blue.svg)](./LICENSE)


A C# like MulticastDelegate template in C++11.

In repository, there is a Microsoft Visual Studio 2017 console project for testing.
