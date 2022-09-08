int plusParam(int a);

int mallocArg(int a) {

    int retVal = plusParam(a);
    return retVal;
}

int plusParam(int a) {
    return a + 1;
}

