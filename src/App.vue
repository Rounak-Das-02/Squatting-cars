<template>
  <div class="flex items-center justify-center">
    <div class="lg:flex lg:flex-row-reverse lg:mx-6 container">
      <section id="container" class="w-full h-screen overflow-scroll">
        <router-view class="mt-28 mx-6 mb-24 lg:flex-grow" />
      </section>
      <NavView />
    </div>
  </div>
</template>

<script>
import NavView from "@/components/NavView.vue";

export default {
  name: "MainView",
  components: {
    NavView,
  },
};
</script>