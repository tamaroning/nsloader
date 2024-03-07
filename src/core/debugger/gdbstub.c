namespace NSLoader {
namespace Core {
namespace Debugger {

constexpr int MP_HASH_SIZE = 100; // ??

static struct {
    int client_waiting;
    int proto_num;
    int server_fd;
    int client_fd;
    int sigval;
    unsigned long int start_addr;
    struct mp_entry *mp_hash[MP_HASH_SIZE];
} rsp;

enum mp_type {
    BP_MEMORY = 0,
    BP_HARDWARE = 1,
    WP_WRITE = 2,
    WP_READ = 3,
    WP_ACCESS = 4
};

struct mp_entry {
    enum mp_type type;
    unsigned long int addr;
    unsigned long int instr;
    struct mp_entry *next;
};

// TODO: WIP

} // namespace Debugger
} // namespace Core
} // namespace NSLoader
