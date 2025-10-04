// Helper function to build expressions
void buildExpr(char*** res, int* resSize, char* expr, char* digits, int target, int idx,
               long long eval, long long last) {

    int n = strlen(digits);
    if (idx == n) {
        if (eval == target) {
            (*resSize)++;
            *res = (char**)realloc(*res, (*resSize) * sizeof(char*));
            (*res)[(*resSize) - 1] = strdup(expr);
        }
        return;
    }

    for (int i = idx; i < n; i++) {

        // Skip numbers with leading zero
        if (i != idx && digits[idx] == '0')
            break;

        char part[105];
        strncpy(part, digits + idx, i - idx + 1);
        part[i - idx + 1] = '\0';

        long long num = atoll(part);

        char newExpr[1005];

        if (idx == 0) {
            buildExpr(res, resSize, part, digits, target, i + 1, num, num);
        } else {
            sprintf(newExpr, "%s+%s", expr, part);
            buildExpr(res, resSize, newExpr, digits, target, i + 1, eval + num, num);

            sprintf(newExpr, "%s-%s", expr, part);
            buildExpr(res, resSize, newExpr, digits, target, i + 1, eval - num, -num);

            sprintf(newExpr, "%s*%s", expr, part);
            buildExpr(res, resSize, newExpr, digits, target, i + 1,
                      eval - last + last * num, last * num);
        }
    }
}

// Function to return expressions evaluating to the target
char** findExpr(char* s, int target, int* returnSize) {
    char** res = NULL;
    *returnSize = 0;
    buildExpr(&res, returnSize, "", s, target, 0, 0, 0);
    return res;
}
