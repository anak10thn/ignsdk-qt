#include "ignprocess.h"

ignprocess::ignprocess(QObject *parent) :
    QObject(parent)
{

}

void ignprocess::exec(const QString &cli){
    proc.setReadChannelMode(QProcess::MergedChannels);
    connect( &proc, SIGNAL(readyReadStandardOutput()), this, SLOT( _out()) );
    connect( &proc, SIGNAL(readyReadStandardError()), this, SLOT( _out()) );
    proc.start(cli);
}

void ignprocess::_out(){
    emit this->out(proc.readAllStandardOutput(),proc.readAllStandardError());
}

void ignprocess::kill(){
    this->proc.kill();
}

int ignprocess::pid(){
    return this->proc.pid();
}
