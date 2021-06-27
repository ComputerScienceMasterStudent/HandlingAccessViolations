#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <eh.h>
#include <stdio.h>
#include <exception>

int throwAccessViolation() {
    char* str = NULL;
    strcpy(str, "test");
    return 0;
}

class SEException : public std::exception
{
private:
    const unsigned int number;
public:
    SEException() noexcept : SEException{ 0 } {}
    SEException(unsigned int n) noexcept : number{ n } {}
    unsigned int getExceptionNumber() const noexcept { return number; }
};

class SETranslator
{
private:
    const _se_translator_function old_SE_translator;
public:
    SETranslator(_se_translator_function new_SE_translator) noexcept
        : old_SE_translator{ _set_se_translator(new_SE_translator) } {}
    ~SETranslator() noexcept { _set_se_translator(old_SE_translator); }
};

#pragma unmanaged
void exceptionHandler(unsigned int u, PEXCEPTION_POINTERS)
{
    throw SEException(u);
}

void testAccessViolation()
{
    try
    {
        throwAccessViolation();
    }
    catch (const SEException& e)
    {
        printf("Caught SE_Exception, error %8.8x\n", e.getExceptionNumber());
    }
    catch (...)
    {
        printf("Caught unexpected SEH exception.\n");
    }
}
#pragma managed

int main() {
    SETranslator scoped_se_translator{ exceptionHandler };
    testAccessViolation();
}
