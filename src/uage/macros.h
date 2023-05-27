

#define DISABLE_COPY_AND_ASSIGN(Class) \
Class(const Class&)            = delete; \
Class(Class&&)                 = delete; \
Class& operator=(const Class&) = delete; \
Class& operator=(Class&&)      = delete;
