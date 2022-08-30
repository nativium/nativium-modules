<script setup>
import { onMounted, ref } from "vue";
import { useQuasar } from "quasar";
import { useWasmModuleStore } from "../../stores/wasm-module";

const wm = useWasmModuleStore();
const q = useQuasar();

const fieldTitle = ref(null);
const fieldBody = ref(null);
const fieldDone = ref(false);

const columns = [
    {
        name: "id",
        required: true,
        label: "ID",
        align: "left",
        field: (row) => row.id,
        format: (val) => `${val}`,
        sortable: true,
    },
    {
        name: "title",
        required: true,
        label: "Title",
        align: "left",
        field: (row) => row.title,
        format: (val) => `${val}`,
        sortable: true,
    },
    {
        name: "body",
        required: true,
        label: "Body",
        align: "left",
        field: (row) => row.body,
        format: (val) => `${val}`,
        sortable: true,
    },
    {
        name: "done",
        required: true,
        label: "Done",
        align: "center",
        field: (row) => row.done,
        format: (val) => `${val}`,
        sortable: true,
    },
    {
        name: "remove",
        label: "Remove",
        align: "center",
        field: (row) => row.id,
        sortable: false,
    },
];

const rows = ref([]);

function onSubmit() {
    const todo = {
        id: BigInt(0),
        title: fieldTitle.value,
        body: fieldBody.value,
        done: fieldDone.value,
        data: {},
        createdAt: new Date(),
        updatedAt: new Date(),
    };

    wm.module.TodoRepository.add(todo);

    onRefresh();

    q.notify({
        type: "positive",
        message: "Todo created",
    });
}

function onReset() {
    fieldTitle.value = null;
    fieldBody.value = null;
    fieldDone.value = false;
}

function onRefresh() {
    if (!wm.module.ApplicationCore.shared().isInitialized()) {
        return;
    }

    q.notify({
        type: "info",
        message: "Loading...",
    });

    new Promise((resolve) => {
        (async function () {
            const data = wm.module.TodoRepository.findAllOrderByCreatedAtDesc();

            const list = data.map((item) => {
                return {
                    id: item.id,
                    title: item.title,
                    body: item.body,
                    done: item.done,
                };
            });

            rows.value = list;

            resolve();
        })();
    }).then(() => {
        q.notify({
            type: "positive",
            message: "List reloaded",
        });
    });
}

function onRemoveById(id) {
    q.notify({
        type: "info",
        message: "Removing...",
    });

    new Promise((resolve) => {
        (async function () {
            wm.module.TodoRepository.removeById(id);
            resolve();
        })();
    }).then(() => {
        q.notify({
            type: "positive",
            message: "Item removed",
        });

        onRefresh();
    });
}

onMounted(() => {
    onRefresh();
});
</script>

<template>
    <div class="container q-pa-md text-center">
        <h4>Todo List</h4>

        <div v-if="wm.module.ApplicationCore.shared().isInitialized()">
            <q-form @submit="onSubmit" @reset="onReset" class="q-gutter-md">
                <q-input
                    rounded
                    outlined
                    type="text"
                    v-model="fieldTitle"
                    label="Title"
                    lazy-rules
                    :rules="[
                        (val) =>
                            (val && val.length > 0) || 'Please type something',
                    ]"
                />

                <q-input
                    rounded
                    outlined
                    type="text"
                    v-model="fieldBody"
                    label="Body"
                    lazy-rules
                    :rules="[
                        (val) =>
                            (val && val.length > 0) || 'Please type something',
                    ]"
                />

                <q-checkbox v-model="fieldDone" label="Done?" />

                <div>
                    <q-btn label="Submit" type="submit" color="primary" />
                    <q-btn
                        label="Reset"
                        type="reset"
                        color="primary"
                        flat
                        class="q-ml-sm"
                    />
                </div>
            </q-form>

            <br />
            <br />

            <q-separator />

            <br />
            <br />

            <q-table
                title="Items"
                :rows="rows"
                :columns="columns"
                row-key="id"
                separator="cell"
            >
                <template v-slot:body-cell-done="props">
                    <q-td :props="props">
                        <q-badge
                            v-if="props.value == 'true'"
                            rounded
                            color="green"
                            :label="props.value"
                        />
                        <q-badge
                            v-else
                            rounded
                            color="red"
                            :label="props.value"
                        />
                    </q-td>
                </template>

                <template v-slot:body-cell-remove="props">
                    <q-td :props="props">
                        <q-btn
                            flat
                            round
                            color="red"
                            icon="delete"
                            @click="onRemoveById(props.value)"
                        />
                    </q-td>
                </template>
            </q-table>
        </div>

        <div v-else>You not initialize core. Initialize it first.</div>
    </div>
</template>
