#!/bin/bash

ROOT=$(pwd)
CONF=${ROOT}/conf/server.conf
BIN=${ROOT}/chat_server
LOG=${ROOT}//log/server.log

proc=$(basename $0)

server_pid=""

function Usage(){
    printf "%s\033[31m%s\033[0m\n" "Usage : ${proc} [start(-s) | stop(-t) | restart(-s) | status(-u)]"
}

if [ $# -ne 1  ]; then
    Usage
    exit 1
fi

function print_log(){
    local msg=$1
        local level=$2
        local curr_time=$(date +%Y_%m_%d_%H:%M:%S)
        printf "%s\n" "[${curr_time}][${msg}][${level}]" >> ${LOG}
}

function server_status(){
    local name=$(basename ${BIN})
        local stat=$(pidof ${name})
        if [  -z ${stat}  ]; then
          return 1
                 return
        fi
        return 0
}

function service_start(){
        sleep 1
    if server_status; then
        echo "server is already running..."
        print_log "server is already running..."
        return
    else
        local server_path=$(dirname ${BIN})
        local server_name=$(basename ${BIN})BIN 
        local server_port=$(grep -E '^PORT :' | awk -F ':' '{print $2}' | tr -d ' ') pushd${server_path}                                                                                ./${server_name} ${server_port} 1> dev/null 2>/dev/null
        #popd 
                                                                                           fi
    if server_status; then
        echo "start success"
        print_log "server is already running..."
    else
        echo "start failed"
        print_log "start server failed" "FATAL"
    fi
}

function service_stop(){
    sleep 1
        if server_status; then
        print_log "server is running stop"
        echo "stop succes"
        kill -9 ${server_pid}
    else
        echo "server is not exist, doesn't need stop"
        print_log "server is not running doesn't need stop" "NOTICE"
    fi
}

function service_restart(){
    service_stop
    service_start
}

function service_status(){
    if server_status; then
        echo "server is running now..."
        print_log "server is running..." "NOTICE"
    else
        echo "server is not running..."
        print_log "server is not running..." "NOTICE"
    fi
}

case $1 in 
    "-s"|"start" )
    service_start
    ;;
    "-t"|"stop" )
    service_stop
    ;;
    "-s"|"restart" )
    service_restart
    ;;
    "-u"|"status" )
    service_status
    ;;
    * )
    Usage
    exit 1
    ;;
esac
                                                                                esac

