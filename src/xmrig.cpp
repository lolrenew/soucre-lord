#include "App.h"
#include "base/kernel/Entry.h"
#include "base/kernel/Process.h"


int main(int argc, char **argv)
{
    using namespace xmrig;

    Process process(argc, argv);
    const Entry::Id entry = Entry::get(process);
    if (entry) {
        return Entry::exec(process, entry);
    }

    App app(&process);

    return app.exec();
}
