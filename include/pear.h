#ifndef PEAR_H
#define PEAR_H

/**
 * Copyright (c) 2015, Willem-Hendrik Thiart
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#define IPC_PIPE_NAME "pear_server_ipc"
#define MAX_CONNECTIONS 512

typedef struct
{
    h2o_context_t ctx;
} pear_thread_t;

typedef struct
{
    MDB_dbi docs;
    MDB_env *db_env;
    h2o_globalconf_t cfg;
    pear_thread_t *threads;
    int nworkers;
    batch_monitor_t batch;

    ck_ht_t etags;

    /* number of etags produced */
    int etag_num;

    /* etag prefix generated once when server boots */
    int etag_prefix;

    uv_mutex_t etag_lock;

} server_t;

extern server_t server;
extern server_t *sv;

#endif /* PEAR_H */
