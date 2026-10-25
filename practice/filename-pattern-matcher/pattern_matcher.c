#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

// Case-insensitive filename matching where "x+" means one or more of the character x.
// Example: "lost+file" matches "lostfile", "losttfile" and "LOSTttFile".

bool matches(const char* filename, const char* pattern) {
    int i = 0, j = 0;

    while (filename[i] != '\0') {
        char c = tolower((unsigned char)filename[i]);

        if (pattern[j] != '\0' && pattern[j + 1] == '+') {
            // "+" case, pattern[j] has to match one or more times
            if (c != tolower((unsigned char)pattern[j])) {
                return false;
            }
            // Stay on this pattern character while the next filename character is the same,
            // otherwise skip past the character and its "+"
            if (tolower((unsigned char)filename[i + 1]) != tolower((unsigned char)pattern[j])) {
                j += 2;
            }
        } else if (pattern[j] == '\0') {
            // The pattern is finished but the filename is not
            return false;
        } else {
            if (c != tolower((unsigned char)pattern[j])) return false;
            j++;
        }
        i++;
    }

    // The filename is finished, so the pattern has to be finished too
    // (skipping any leftover "+")
    while (pattern[j] == '+') j++;
    return pattern[j] == '\0';
}

int main(void) {
    // {filename, pattern, expected result}
    struct { const char* f; const char* p; bool expected; } tests[] = {
        // Should match
        {"lostfile",       "lost+file", true},
        {"losttfile",      "lost+file", true},
        {"lostttfile",     "lost+file", true},
        {"losttttfile",    "lost+file", true},
        {"lostFile",       "lost+file", true},
        {"LOStttttttFile", "lost+file", true},

        // Should not match
        {"lo",             "lost+file", false}, // too short
        {"losttfileXXX",   "lost+file", false}, // extra characters at the end
        {"losfile",        "lost+file", false}, // no t at all
        {"lost+",          "lost+file", false}, // too short, no "file" at the end
        {"lostfile_",      "lost+file", false}, // extra "_" at the end

        // Several "+" in one pattern
        {"losssttfile",    "los+t+file", true},
        {"lossfile",       "los+t+file", false}, // no t
    };

    int n = sizeof(tests) / sizeof(tests[0]);
    int passed = 0;

    for (int k = 0; k < n; k++) {
        bool result = matches(tests[k].f, tests[k].p);
        bool ok = (result == tests[k].expected);
        printf("[%s] filename=%-20s pattern=%-12s expected=%s result=%s\n",
            ok ? "OK  " : "FAIL",
            tests[k].f,
            tests[k].p,
            tests[k].expected ? "true " : "false",
            result            ? "true " : "false");
        if (ok) passed++;
    }

    printf("\n%d/%d tests passed\n", passed, n);
    return 0;
}
