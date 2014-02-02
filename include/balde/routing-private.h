/*
 * balde: A microframework for C based on GLib and bad intentions.
 * Copyright (C) 2013-2014 Rafael G. Martins <rafael@rafaelmartins.eng.br>
 *
 * This program can be distributed under the terms of the LGPL-2 License.
 * See the file COPYING.
 */

#ifndef _BALDE_ROUTING_PRIVATE_H
#define _BALDE_ROUTING_PRIVATE_H

#include <glib.h>
#include <balde/routing.h>

typedef struct {
    const gchar *endpoint;
    const gchar *rule;
    GRegex *regex;
    balde_http_method_t method;
} balde_url_rule_t;

const gboolean balde_url_match(const gchar *path, const gchar *rule,
    GHashTable **matches);
gchar* balde_dispatch_from_path(GSList *views, const gchar *path,
    GHashTable **matches);
const balde_http_method_t balde_http_method_str2enum(const gchar *method);
gchar* balde_list_allowed_methods(const balde_http_method_t method);
GRegex* balde_parse_url_rule(const gchar *rule, GError **error);

#endif /* _BALDE_ROUTING_PRIVATE_H */
