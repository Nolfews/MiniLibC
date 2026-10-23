#include <stdio.h>

#define RESET   "\x1b[0m"
#define GREEN   "\x1b[32m"
#define RED     "\x1b[31m"
#define BLUE    "\x1b[34m"
#define YELLOW  "\x1b[33m"
#define ORANGE  "\x1b[38;5;214m"

extern size_t strlen(const char *str);
extern char *strchr(const char *str, int c);
extern char *strrchr(const char *str, int c);
extern int strcmp(const char *str, const char *comp);
extern int strncmp(const char *str1, const char *str2, size_t n);
extern int strcasecmp(const char *str1, const char *str2);
extern char *strstr(const char *haystack, const char *needle);
extern char *strpbrk(const char *haystack, const char *accept);
extern size_t strcspn(const char *haystack, const char *reject);
extern void *memset(void *s, int c, size_t n);
extern void *memcpy(void *dest, const void *src, size_t n);
extern void *memmove(void *dst, const void *src, size_t n);

typedef struct {
    const char *str;
    size_t expected;
    const char *description;
} StrlenTestCase;

typedef struct {
    const char *str;
    char search;
    const char *expected;
    const char *description;
} StrchrTestCase;

typedef struct {
    const char *str1;
    const char *str2;
    int expected;
    const char *description;
} StrcmpTestCase;

typedef struct {
    const char *str1;
    const char *str2;
    size_t n;
    int expected;
    const char *description;
} StrncmpTestCase;

typedef struct {
    const char *str1;
    const char *str2;
    int expected;
    const char *description;
} StrcasecmpTestCase;

typedef struct {
    const char *haystack;
    const char *needle;
    const char *expected;
    const char *description;
} StrstrTestCase;

typedef struct {
    const char *haystack;
    const char *accept;
    const char *expected;
    const char *description;
} StrpbrkTestCase;

typedef struct {
    const char *haystack;
    const char *reject;
    size_t expected;
    const char *description;
} StrcspnTestCase;

typedef struct {
    char input[20];
    int fill_char;
    size_t size;
    char expected[20];
    const char *description;
} MemsetTestCase;

typedef struct {
    char input_dest[20];
    char input_src[20];
    size_t size;
    char expected[20];
    const char *description;
} MemcpyTestCase;

typedef struct {
    char input_dest[20];
    char input_src[20];
    size_t size;
    char expected[20];
    const char *description;
} MemmoveTestCase;

void copy_array(char *dest, const char *src, size_t size) {
    for (size_t i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}

int compare_arrays(const char *arr1, const char *arr2, size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            return 0;
        }
    }
    return 1;
}

int run_strlen_test(const StrlenTestCase *test) {
    size_t result_custom = strlen(test->str);

    printf(YELLOW "Test: %s\n" RESET, test->description);
    printf(BLUE "String: \"%s\"\n" RESET, test->str);
    printf(ORANGE "Votre fonction: %zu\n" RESET, result_custom);
    printf(ORANGE "Valeur attendue: %zu\n" RESET, test->expected);

    if (result_custom == test->expected) {
        printf(GREEN "✅ Test réussi\n" RESET);
        printf("\n");
        return 1;
    } else {
        printf(RED "❌ Test échoué\n" RESET);
        printf("\n");
        return 0;
    }
}

int run_strchr_test(const StrchrTestCase *test) {
    char *result_custom = strchr(test->str, test->search);

    printf(YELLOW "Test: %s\n" RESET, test->description);
    printf(BLUE "String: \"%s\"\n" RESET, test->str);
    printf(BLUE "Recherche: '%c'\n" RESET, test->search);
    printf(ORANGE "Votre fonction retourne: %s\n" RESET, result_custom ? result_custom : "(null)");
    printf(ORANGE "Valeur attendue: %zu\n" RESET, test->expected ? test->expected : "(null)");

    if ((result_custom == NULL && test->expected == NULL) ||
        (result_custom != NULL && test->expected != NULL && strcmp(result_custom, test->expected) == 0)) {
        printf(GREEN "✅ Test réussi\n" RESET);
        printf("\n");
        return 1;
    } else {
        printf(RED "❌ Test échoué\n" RESET);
        printf("\n");
        return 0;
    }
}

int run_strrchr_test(const StrchrTestCase *test) {
    char *result_custom = strrchr(test->str, test->search);

    printf(YELLOW "Test: %s\n" RESET, test->description);
    printf(BLUE "String: \"%s\"\n" RESET, test->str);
    printf(BLUE "Recherche: '%c'\n" RESET, test->search);
    printf(ORANGE "Votre fonction retourne: %s\n" RESET, result_custom ? result_custom : "(null)");
    printf(ORANGE "Valeur attendue: %s\n" RESET, test->expected ? test->expected : "(null)");

    if ((result_custom == NULL && test->expected == NULL) ||
        (result_custom != NULL && test->expected != NULL && strcmp(result_custom, test->expected) == 0)) {
        printf(GREEN "✅ Test réussi\n" RESET);
        printf("\n");
        return 1;
    } else {
        printf(RED "❌ Test échoué\n" RESET);
        printf("\n");
        return 0;
    }
}

int run_strcmp_test(const StrcmpTestCase *test) {
    int result_custom = strcmp(test->str1, test->str2);

    printf(YELLOW "Test: %s\n" RESET, test->description);
    printf(BLUE "String 1: \"%s\"\n" RESET, test->str1);
    printf(BLUE "String 2: \"%s\"\n" RESET, test->str2);
    printf(ORANGE "Votre fonction retourne: %d\n" RESET, result_custom);
    printf(ORANGE "Valeur attendue: %d\n" RESET, test->expected);

    if (result_custom == test->expected) {
        printf(GREEN "✅ Test réussi\n" RESET);
        printf("\n");
        return 1;
    } else {
        printf(RED "❌ Test échoué\n" RESET);
        printf("\n");
        return 0;
    }
}

int run_strncmp_test(const StrncmpTestCase *test) {
    int result_custom = strncmp(test->str1, test->str2, test->n);

    printf(YELLOW "Test: %s\n" RESET, test->description);
    printf(BLUE "String 1: \"%s\"\n" RESET, test->str1);
    printf(BLUE "String 2: \"%s\"\n" RESET, test->str2);
    printf(ORANGE "Votre fonction retourne: %d\n" RESET, result_custom);
    printf(ORANGE "Valeur attendue: %d\n" RESET, test->expected);

    if (result_custom == test->expected) {
        printf(GREEN "✅ Test réussi\n" RESET);
        printf("\n");
        return 1;
    } else {
        printf(RED "❌ Test échoué\n" RESET);
        printf("\n");
        return 0;
    }
}

int run_strcasecmp_test(const StrcasecmpTestCase *test) {
    int result_custom = strcasecmp(test->str1, test->str2);

    printf(YELLOW "Test: %s\n" RESET, test->description);
    printf(BLUE "String 1: \"%s\"\n" RESET, test->str1);
    printf(BLUE "String 2: \"%s\"\n" RESET, test->str2);
    printf(ORANGE "Votre fonction retourne: %d\n" RESET, result_custom);
    printf(ORANGE "Valeur attendue: %d\n" RESET, test->expected);

    if (result_custom == test->expected) {
        printf(GREEN "✅ Test réussi\n" RESET);
        printf("\n");
        return 1;
    } else {
        printf(RED "❌ Test échoué\n" RESET);
        printf("\n");
        return 0;
    }
}

int run_strstr_test(const StrstrTestCase *test) {
    char *result_custom = strstr(test->haystack, test->needle);

    printf(YELLOW "Test: %s\n" RESET, test->description);
    printf(BLUE "Haystack: \"%s\"\n" RESET, test->haystack);
    printf(BLUE "Needle: \"%s\"\n" RESET, test->needle);
    printf(ORANGE "Votre fonction retourne: %s\n" RESET, result_custom ? result_custom : "(null)");
    printf(ORANGE "Valeur attendue: %s\n" RESET, test->expected ? test->expected : "(null)");

    if ((result_custom == NULL && test->expected == NULL) ||
        (result_custom != NULL && test->expected != NULL && strcmp(result_custom, test->expected) == 0)) {
        printf(GREEN "✅ Test réussi\n" RESET);
        printf("\n");
        return 1;
    } else {
        printf(RED "❌ Test échoué\n" RESET);
        printf("\n");
        return 0;
    }
}

int run_strpbrk_test(const StrpbrkTestCase *test) {
    char *result_custom = strpbrk(test->haystack, test->accept);

    printf(YELLOW "Test: %s\n" RESET, test->description);
    printf(BLUE "Haystack: \"%s\"\n" RESET, test->haystack);
    printf(BLUE "Accept: \"%s\"\n" RESET, test->accept);
    printf(ORANGE "Votre fonction retourne: %s\n" RESET, result_custom ? result_custom : "(null)");
    printf(ORANGE "Valeur attendue: %s\n" RESET, test->expected ? test->expected : "(null)");

    if ((result_custom == NULL && test->expected == NULL) ||
        (result_custom != NULL && test->expected != NULL && strcmp(result_custom, test->expected) == 0)) {
        printf(GREEN "✅ Test réussi\n" RESET);
        printf("\n");
        return 1;
    } else {
        printf(RED "❌ Test échoué\n" RESET);
        printf("\n");
        return 0;
    }
}

int run_strcspn_test(const StrcspnTestCase *test) {
    size_t result_custom = strcspn(test->haystack, test->reject);

    printf(YELLOW "Test: %s\n" RESET, test->description);
    printf(BLUE "Haystack: \"%s\"\n" RESET, test->haystack);
    printf(BLUE "Reject: \"%s\"\n" RESET, test->reject);
    printf(ORANGE "Votre fonction retourne: %zu\n" RESET, result_custom);
    printf(ORANGE "Valeur attendue: %zu\n" RESET, test->expected);

    if (result_custom == test->expected) {
        printf(GREEN "✅ Test réussi\n" RESET);
        printf("\n");
        return 1;
    } else {
        printf(RED "❌ Test échoué\n" RESET);
        printf("\n");
        return 0;
    }
}

int run_memset_test(const MemsetTestCase *test) {
    char buffer[20];

    copy_array(buffer, test->input, sizeof(buffer));
    memset(buffer, test->fill_char, test->size);

    printf(YELLOW "Test: %s\n" RESET, test->description);
    printf(BLUE "Avant: \"%s\"\n" RESET, test->input);
    printf(BLUE "Caractère: '%c' (%d)\n" RESET, test->fill_char, test->fill_char);
    printf(BLUE "Taille: %zu\n" RESET, test->size);
    printf(ORANGE "Résultat obtenu: \"%s\"\n" RESET, buffer);
    printf(ORANGE "Résultat attendu: \"%s\"\n" RESET, test->expected);

    if (compare_arrays(buffer, test->expected, sizeof(buffer))) {
        printf(GREEN "✅ Test réussi\n" RESET);
        printf("\n");
        return 1;
    } else {
        printf(RED "❌ Test échoué\n" RESET);
        printf("\n");
        return 0;
    }
}

int run_memcpy_test(const MemcpyTestCase *test) {
    char buffer_dest[20];
    char buffer_src[20];

    copy_array(buffer_dest, test->input_dest, sizeof(buffer_dest));
    copy_array(buffer_src, test->input_src, sizeof(buffer_src));
    memcpy(buffer_dest, buffer_src, test->size);
    printf(YELLOW "Test: %s\n" RESET, test->description);
    printf(BLUE "Avant: \"%s\"\n" RESET, test->input_dest);
    printf(BLUE "Source: \"%s\"\n" RESET, test->input_src);
    printf(BLUE "Taille: %zu\n" RESET, test->size);
    printf(ORANGE "Résultat obtenu: \"%s\"\n" RESET, buffer_dest);
    printf(ORANGE "Résultat attendu: \"%s\"\n" RESET, test->expected);

    if (compare_arrays(buffer_dest, test->expected, sizeof(buffer_dest))) {
        printf(GREEN "✅ Test réussi\n\n" RESET);
        return 1;
    } else {
        printf(RED "❌ Test échoué\n\n" RESET);
        return 0;
    }
}

int run_memmove_test(const MemmoveTestCase *test) {
    char buffer_dest[20];
    char buffer_src[20];

    copy_array(buffer_dest, test->input_dest, sizeof(buffer_dest));
    copy_array(buffer_src, test->input_src, sizeof(buffer_src));

    memmove(buffer_dest, buffer_src, test->size);

    printf(YELLOW "Test: %s\n" RESET, test->description);
    printf(BLUE "Avant: \"%s\"\n" RESET, test->input_dest);
    printf(BLUE "Source: \"%s\"\n" RESET, test->input_src);
    printf(BLUE "Taille: %zu\n" RESET, test->size);
    printf(ORANGE "Résultat obtenu: \"%s\"\n" RESET, buffer_dest);
    printf(ORANGE "Résultat attendu: \"%s\"\n" RESET, test->expected);

    if (compare_arrays(buffer_dest, test->expected, sizeof(buffer_dest))) {
        printf(GREEN "✅ Test réussi\n\n" RESET);
        return 1;
    } else {
        printf(RED "❌ Test échoué\n\n" RESET);
        return 0;
    }
}

int main()
{
    int nb_test = 0;
    int total = 0;

    // === TESTS STRLEN ===
    StrlenTestCase strlen_tests[] = {
        {"", 0, "Chaîne vide"},
        {"A", 1, "Un seul caractère"},
        {"Hello", 5, "Mot simple"},
        {"Hello, World!", 13, "Phrase avec ponctuation"},
        {"\n", 1, "Saut de ligne"},
        {"\t", 1, "Tabulation"},
        {"Hello\0World", 5, "Chaîne avec un caractère NULL"},
        {"1234567890", 10, "Chiffres"},
        {NULL, 0, "NULL (comportement indéfini, ne pas exécuter)"}
    };

    printf(BLUE "=== Tests de strlen ===\n\n" RESET);
    for (int i = 0; strlen_tests[i].str != NULL; i++) {
        nb_test += run_strlen_test(&strlen_tests[i]);
        total++;
    }

    // === TESTS STRCHR ===
    StrchrTestCase strchr_tests[] = {
        {"Hello, World!", 'W', "World!", "Recherche d'un caractère présent"},
        {"Hello, World!", 'H', "Hello, World!", "Premier caractère"},
        {"Hello, World!", '!', "!", "Dernier caractère"},
        {"Hello, World!", 'z', NULL, "Caractère absent"},
        {"Hello, World!", '\0', "Hello, World!" + 13, "Recherche du caractère NULL"},
        {"", 'a', NULL, "Recherche dans une chaîne vide"},
        {"abcdefabc", 'a', "abcdefabc", "Premier 'a'"},
        {"abcdefabc", 'c', "cdefabc", "Dernier 'c'"},
        {"abcdefabc", 'b', "bcdefabc", "Premier 'b'"},
        {NULL, 0, NULL, "NULL (comportement indéfini, ne pas exécuter)"}
    };

    printf(BLUE "=== Tests de strchr ===\n\n" RESET);
    for (int i = 0; strchr_tests[i].str != NULL; i++) {
        nb_test += run_strchr_test(&strchr_tests[i]);
        total++;
    }

    // === TESTS STRRCHR ===
    StrchrTestCase strrchr_tests[] = {
        {"Hello, World!", 'W', "World!", "Recherche du dernier caractère présent"},
        {"Hello, World!", 'H', "Hello, World!", "Premier caractère"},
        {"Hello, World!", '!', "!", "Dernier caractère"},
        {"Hello, World!", 'z', NULL, "Caractère absent"},
        {"Hello, World!", '\0', "\0", "Recherche du caractère NULL"},
        {"", 'a', NULL, "Recherche dans une chaîne vide"},
        {"abcdefabc", 'a', "abc", "Premier 'a'"},
        {"abcdefabc", 'c', "c", "Dernier 'c'"},
        {"abcdefabc", 'b', "bc", "Dernier 'b'"},
        {NULL, 0, NULL, "NULL (comportement indéfini, ne pas exécuter)"}
    };

    printf(BLUE "=== Tests de strrchr ===\n\n" RESET);
    for (int i = 0; strrchr_tests[i].str != NULL; i++) {
        nb_test += run_strrchr_test(&strrchr_tests[i]);
        total++;
    }

    // === TESTS STRCMP ===
    StrcmpTestCase strcmp_tests[] = {
        {"Hello", "Hello", 0, "Chaînes identiques"},
        {"Hello", "World", -15, "Première chaîne inférieure"},
        {"World", "Hello", 15, "Deuxième chaîne inférieure"},
        {"Hello", "Hell", 111, "Chaînes de longueurs différentes"},
        {"", "Hello", -72, "Chaîne vide comparée à une chaîne non vide"},
        {"Hello", "", 72, "Chaîne non vide comparée à une chaîne vide"},
        {"", "", 0, "Deux chaînes vides"},
        {NULL, NULL, 0, "NULL (comportement indéfini, ne pas exécuter)"}
    };

    printf(BLUE "=== Tests de strcmp ===\n\n" RESET);
    for (int i = 0; strcmp_tests[i].str1 != NULL; i++) {
        nb_test += run_strcmp_test(&strcmp_tests[i]);
        total++;
    }

    // === TESTS STRNCMP ===
    StrncmpTestCase strncmp_tests[] = {
        {"Hello", "Hello", 5, 0, "Chaînes identiques sur les 5 premiers caractères"},
        {"Hello", "Hello", 3, 0, "Chaînes identiques sur les 3 premiers caractères"},
        {"Hello", "Helloo", 5, 0, "Chaînes identiques sur les 5 premiers caractères (différentes après)"},
        {"Hello", "World", 3, -15, "Chaînes différentes dès le premier caractère"},
        {"Hello", "Hel", 3, 0, "Chaînes identiques sur 3 caractères"},
        {"Hello", "HELLO", 5, 32, "Différence entre lettres majuscules et minuscules"},
        {"abc", "abcd", 4, -100, "Chaînes identiques sur les 4 premiers caractères"},
        {"abc", "abz", 3, -23, "Chaînes identiques sur 3 caractères"},
        {NULL, NULL, 0, 0, "NULL (comportement indéfini, ne pas exécuter)"}
    };

    printf(BLUE "=== Tests de strncmp ===\n\n" RESET);
    for (int i = 0; strncmp_tests[i].str1 != NULL; i++) {
        nb_test += run_strncmp_test(&strncmp_tests[i]);
        total++;
    }

    // === TESTS STRCASECMP ===
    StrcasecmpTestCase strcasecmp_tests[] = {
        {"Hello", "hello", 0, "Chaînes identiques (différence de casse)"},
        {"apple", "APPLE", 0, "Chaînes identiques (différence de casse)"},
        {"abc", "ABC", 0, "Chaînes identiques (différence de casse)"},
        {"Hello", "World", -15, "Chaînes différentes"},
        {"hello", "hell", 111, "Chaînes différentes"},
        {"", "", 0, "Deux chaînes vides"},
        {"Hello", "", 72, "Chaîne non vide comparée à une chaîne vide"},
        {NULL, NULL, 0, "NULL (comportement indéfini, ne pas exécuter)"}
    };

    printf(BLUE "=== Tests de strcasecmp ===\n\n" RESET);
    for (int i = 0; i < strcasecmp_tests[i].str1 != NULL; i++) {
        nb_test += run_strcasecmp_test(&strcasecmp_tests[i]);
        total++;
    }

    // === TESTS STRSTR ===
    StrstrTestCase strstr_tests[] = {
        {"Hello, World!", "World", "World!", "Recherche de sous-chaîne présente"},
        {"Hello, World!", "Hello", "Hello, World!", "Sous-chaîne au début"},
        {"Hello, World!", "!", "!", "Sous-chaîne à la fin"},
        {"Hello, World!", "World!", "World!", "Sous-chaîne à la fin avec ponctuation"},
        {"Hello, World!", "xyz", NULL, "Sous-chaîne absente"},
        {"", "a", NULL, "Recherche dans une chaîne vide"},
        {"abcdefabc", "def", "defabc", "Sous-chaîne en milieu de chaîne"},
        {"abcdefabc", "abc", "abcdefabc", "Sous-chaîne au début"},
        {"abcdefabc", "xyz", NULL, "Sous-chaîne absente"},
        {NULL, NULL, NULL, "NULL (comportement indéfini, ne pas exécuter)"}
    };

    printf(BLUE "=== Tests de strstr ===\n\n" RESET);
    for (int i = 0; strstr_tests[i].haystack != NULL; i++) {
        nb_test += run_strstr_test(&strstr_tests[i]);
        total++;
    }

    // === TESTS STRPBRK ===
    StrpbrkTestCase strpbrk_tests[] = {
        {"Hello, World!", "aeiou", "ello, World!", "Première occurrence de 'a', 'e', 'i', 'o', ou 'u'"},
        {"Hello, World!", "xyz", NULL, "Aucun des caractères trouvés"},
        {"abcdefabc", "def", "defabc", "Première occurrence parmi 'd', 'e', 'f'"},
        {"abcdefabc", "123", NULL, "Caractères non trouvés"},
        {"abcdefabc", "c", "cdefabc", "Caractère unique trouvé"},
        {"abcdefabc", "abc", "abcdefabc", "Premier caractère trouvé parmi 'a', 'b', 'c'"},
        {"", "a", NULL, "Recherche dans une chaîne vide"},
        {"abcdefabc", "abcxyz", "abcdefabc", "Premier caractère trouvé parmi 'a', 'b', 'c'"},
        {NULL, NULL, NULL, "NULL (comportement indéfini, ne pas exécuter)"}
    };

    printf(BLUE "=== Tests de strpbrk ===\n\n" RESET);
    for (int i = 0; strpbrk_tests[i].haystack != NULL; i++) {
        nb_test += run_strpbrk_test(&strpbrk_tests[i]);
        total++;
    }

    // === TESTS STRCSPN ===
    StrcspnTestCase strcspn_tests[] = {
        {"Hello, World!", "aeiou", 1, "Premier caractère dans haystack est 'H' et est différent de reject"},
        {"Hello, World!", "a", 13, "Premier caractère dans haystack est 'H' et est différent de reject (seul 'a' est rejeté)"},
        {"Hello, World!", "o", 4, "Le premier 'o' dans 'Hello'"},
        {"Hello, World!", "World", 2, "Le premier caractère est dans reject"},
        {"", "aeiou", 0, "Chaîne vide dans haystack"},
        {"Hello, World!", "", 13, "Reject est vide, retourne la longueur totale de haystack"},
        {"abcdef", "z", 6, "Aucun caractère n'est dans reject, retourne la longueur totale de haystack"},
        {NULL, NULL, 0, "NULL (comportement indéfini, ne pas exécuter)"}
    };

    printf(BLUE "=== Tests de strcspn ===\n\n" RESET);
    for (int i = 0; strcspn_tests[i].haystack != NULL; i++) {
        nb_test += run_strcspn_test(&strcspn_tests[i]);
        total++;
    }

    // === TESTS MEMSET ===
    MemsetTestCase memset_tests[] = {
        {"abcdefghij", 'X', 5, "XXXXXfghij", "Remplit 5 caractères avec 'X'"},
        {"abcdefghij", 'A', 10, "AAAAAAAAAA", "Remplit toute la chaîne avec 'A'"},
        {"abcdefghij", 0, 5, "\0\0\0\0\0fghij", "Remplit 5 premiers caractères avec '\\0'"},
        {"abcdefghij", 'Z', 0, "abcdefghij", "Ne change rien (taille = 0)"},
        {"abcdefghij", '1', 3, "111defghij", "Remplit 3 caractères avec '1'"},
        {NULL, 0, 0, "", "NULL (comportement indéfini, ne pas exécuter)"}
    };

    printf(BLUE "=== Tests de memset ===\n\n" RESET);
    for (int i = 0; i < 5; i++) {
        nb_test += run_memset_test(&memset_tests[i]);
        total++;
    }

    // === TESTS MEMCPY ===
    MemcpyTestCase memcpy_tests[] = {
        {"abcdefghij", "1234567890", 5, "12345fghij", "Copie les 5 premiers caractères"},
        {"abcdefghij", "1234567890", 10, "1234567890", "Copie toute la chaîne"},
        {"abcdefghij", "1234567890", 3, "123defghij", "Copie les 3 premiers caractères"},
        {"abcdefghij", "1234567890", 0, "abcdefghij", "Ne change rien (taille = 0)"},
        {"abcdefghij", "abcdefghij", 5, "abcdefghij", "Copie 5 premiers caractères sur la même chaîne"},
        {"abcdefghij", "1234567890", 10, "1234567890", "Copie dans une destination vide"}
    };

    printf(BLUE "=== Tests de memcpy ===\n\n" RESET);
    for (int i = 0; i < 6; i++) {
        nb_test += run_memcpy_test(&memcpy_tests[i]);
        total++;
    }

    // === TESTS MEMMOVE ===
    MemmoveTestCase memmove_tests[] = {
        { "abcdefg", "1234567", 7, "1234567", "Déplacement d'une source vers une destination différente" },
        { "abcdefg", "12345", 5, "12345fg", "Déplacement partiel d'une chaîne" },
        { "abcde", "fghij", 5, "fghij", "Source et destination sont égales" },
        { "abcdef", "123456", 3, "123def", "Déplacement partiel avec des superpositions" },
        { "", "test", 4, "test", "Cas avec chaîne source vide" },
        { "hello", "world", 0, "hello", "Test avec taille nulle" },
        { NULL, NULL, 0, NULL, "NULL (comportement indéfini, ne pas exécuter)" }
    };

    printf(BLUE "=== Tests de memmove ===\n\n" RESET);
    for (int i = 0; i < 5; i++) {
        nb_test += run_memmove_test(&memmove_tests[i]);
        total++;
    }

    // === TESTS INDEX ===
    StrchrTestCase index_tests[] = {
        {"Hello, World!", 'W', "World!", "Recherche d'un caractère présent"},
        {"Hello, World!", 'H', "Hello, World!", "Premier caractère"},
        {"Hello, World!", '!', "!", "Dernier caractère"},
        {"Hello, World!", 'z', NULL, "Caractère absent"},
        {"Hello, World!", '\0', "Hello, World!" + 13, "Recherche du caractère NULL"},
        {"", 'a', NULL, "Recherche dans une chaîne vide"},
        {"abcdefabc", 'a', "abcdefabc", "Premier 'a'"},
        {"abcdefabc", 'c', "cdefabc", "Dernier 'c'"},
        {"abcdefabc", 'b', "bcdefabc", "Premier 'b'"},
        {NULL, 0, NULL, "NULL (comportement indéfini, ne pas exécuter)"}
    };

    printf(BLUE "=== Tests de index ===\n\n" RESET);
    for (int i = 0; index_tests[i].str != NULL; i++) {
        nb_test += run_strchr_test(&index_tests[i]);
        total++;
    }

    // === TESTS RINDEX ===
    StrchrTestCase rindex_tests[] = {
        {"Hello, World!", 'W', "World!", "Recherche du dernier caractère présent"},
        {"Hello, World!", 'H', "Hello, World!", "Premier caractère"},
        {"Hello, World!", '!', "!", "Dernier caractère"},
        {"Hello, World!", 'z', NULL, "Caractère absent"},
        {"Hello, World!", '\0', "\0", "Recherche du caractère NULL"},
        {"", 'a', NULL, "Recherche dans une chaîne vide"},
        {"abcdefabc", 'a', "abc", "Premier 'a'"},
        {"abcdefabc", 'c', "c", "Dernier 'c'"},
        {"abcdefabc", 'b', "bc", "Dernier 'b'"},
        {NULL, 0, NULL, "NULL (comportement indéfini, ne pas exécuter)"}
    };

    printf(BLUE "=== Tests de rindex ===\n\n" RESET);
    for (int i = 0; rindex_tests[i].str != NULL; i++) {
        nb_test += run_strrchr_test(&rindex_tests[i]);
        total++;
    }

    printf(GREEN "Tests réussis: %i sur %i\n" RESET , nb_test, total);
    printf(RED "Tests échoués: %i sur %i\n" RESET, total - nb_test, total);
    return 0;
}
