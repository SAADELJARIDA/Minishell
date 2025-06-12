#include "../minishell.h"

int main() {
    char *input;
    char *env;
    env = getenv("PATH");
    printf("%s",env);
    return 0;
}
