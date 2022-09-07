// Created by Zcr on 2022/9/7.

int switchLab(int a) {
    int retVal = -1;
    switch (a) {
        case 100:
            retVal = 0;
            break;
        case 101:
            retVal = 1;
            break;
        case 102:
            retVal = 2;
        case 105:
            retVal = 3;
            break;
        default:
            retVal = -2;
    }
    return retVal;
}

int main(){

}

