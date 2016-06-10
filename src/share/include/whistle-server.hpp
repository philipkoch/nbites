#ifndef WHISTLE_SERVER_SHARE_H
#define WHISTLE_SERVER_SHARE_H

#include "whistle.hpp"

namespace whistle {

    extern bool listening;
    extern bool was_heard;
    extern nbl::io::client_socket_t man_socket;
    extern nbl::io::server_socket_t whs_socket;

    extern void whistle_cleanup();

    static inline void * server_loop(void * unused) {

        if (nbl::io::create_pipe(whs_socket, PORT)) {
            NBL_ERROR("could not create pipe in whistle!");
            whistle_cleanup();
        }

        while (whs_socket > 0) {
            man_socket = accept(whs_socket, (struct sockaddr*)NULL, NULL);

            if (man_socket < 0) {
                NBL_ERROR("could not accept pipe in whistle!");
                close(whs_socket);
                whistle_cleanup();
            }

            whistle_request recv;
            whistle_status  sent;

            if (listening) {
                if (was_heard) {
                    sent = HEARD;
                } else {
                    sent = LISTENING;
                }
            } else {
                sent = NOT_LISTENING;
            }

            if (nbl::io::send_exact(man_socket, 1, &sent, 0)) continue;
            if (nbl::io::recv_exact(man_socket, 1, &recv, 0)) continue;

            switch(recv) {
                case START:
                    listening = true;
                    was_heard = false;
                    break;
                case QUERY:
                    listening = !was_heard;
                    break;
                case STOP:
                    listening = false;
                    was_heard = false;
                default:;
            }

//            if (time(NULL) % 10 == 0) { close(whs_socket); close(man_socket); return NULL;}
        }

        return NULL;
    }

    static inline void create_server() {
        NBL_WARN("whistle::create_server()");
        pthread_t server_thread;
        pthread_create(&server_thread, NULL, server_loop, NULL);
        pthread_detach(server_thread);
    }
    
}

#endif