#include <capnzero-base-msgs/string.capnp.h>

#include <zmq.h>

#include <capnzero/Common.h>
#include <capnzero/Subscriber.h>
#include <capnp/serialize.h>

#include <string>

#include <signal.h>

std::string cmd = "flite -t ";

static bool interrupted = false;
static void s_signal_handler(int signal_value)
{
    interrupted = true;
}

static void s_catch_signals(void)
{
    struct sigaction action;
    action.sa_handler = s_signal_handler;
    action.sa_flags = 0;
    sigemptyset(&action.sa_mask);
    sigaction(SIGINT, &action, NULL);
    sigaction(SIGTERM, &action, NULL);
}

void talk(::capnp::FlatArrayMessageReader& reader)
{
    std::system((cmd+"\""+reader.getRoot<capnzero::String>().getString().cStr()+"\"").c_str());
//    std::system((cmd+"\""+reader.getRoot<capnzero::String>().toString().flatten().cStr()+"\"").c_str());
}

int main(int argc, char **argv)
{
    // register signals
    s_catch_signals();


    // setup capnzero
    void* ctx = zmq_ctx_new();
    capnzero::Subscriber* sub = new capnzero::Subscriber(ctx, argv[1], &talk);
    sub->addAddress(capnzero::CommType::IPC, "@capnzero.ipc");
    sub->connect();
//    sub->connect(capnzero::CommType::UDP, "*:5555");

    // wait
    while (!interrupted) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    // clean up
    delete sub;
    zmq_ctx_term(ctx);

    return 0;
}

