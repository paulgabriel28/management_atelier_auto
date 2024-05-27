#ifndef _ENUM
#define _ENUM

// MARK: enum
enum typeAngajat {
    parametruNULLtype = -1,
    ANGAJAT = 0,
    DIRECTOR,
    MECANIC,
    ASISTENT
};

enum atributeAngajati {
    atributNULL = -1,
    NUME = 0,
    PRENUME,
    dataNASTERE,
    dataANGAJARE
};

enum vectorMasiniPoz {
    vectorNULL = -1,
    MASINA1 = 0,
    MASINA2,
    MASINA3,
    AUTOBUZ,
    CAMION
};

enum typeMasini {
    tipNULL = -1,
    tipMASINA = 0,
    tipSTANDARD,
    tipAUTOBUZ,
    tipCAMION
};

enum dataEnum {
    ZIUA = 0,
    LUNA,
    AN
};

enum typeTransmisie {
    transmisieNULL = -1,
    MANUAL = 0,
    AUTOMAT
};

#endif