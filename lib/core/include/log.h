#ifndef __INC_LIBTHECORE_LOG_H__
#define __INC_LIBTHECORE_LOG_H__

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
    extern int log_init(void);
    extern void log_destroy(void);
    extern void log_rotate(void);

	// 로그 레벨 처리 (레벨은 bitvector로 처리된다)
	extern void log_set_level(unsigned int level);
	extern void log_unset_level(unsigned int level);

	// 로그 파일을 얼만큼 보관하는가에 대한 함수
	extern void log_set_expiration_days(unsigned int days);
	extern int log_get_expiration_days(void);

    extern void _sys_err(const char *func, int line, const char *format, ...);
    extern void sys_log_header(const char *header);
    extern void sys_log(unsigned int lv, const char *format, ...);
    extern void pt_log(const char *format, ...);

#define sys_err(fmt, args...) _sys_err(__FUNCTION__, __LINE__, fmt, ##args)
#ifdef __cplusplus
}
#endif	// __cplusplus

#endif	// __INC_LOG_H__
