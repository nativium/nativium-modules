// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

import { Todo } from "./app-domain"

export interface TodoRepository {
}
export interface TodoRepository_statics {
    truncate(): void;
    findById(id: bigint): Todo;
    findAllOrderByCreatedAtDesc(): Array<Todo>;
    findByTitle(title: string): Array<Todo>;
    removeById(id: bigint): boolean;
    update(id: bigint, todo: Todo): bigint;
    insert(todo: Todo): bigint;
    add(todo: Todo): bigint;
    setDoneById(id: bigint, done: boolean): boolean;
    count(): bigint;
}

export interface AppRepository_statics {
    TodoRepository: TodoRepository_statics;
}
